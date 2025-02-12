// IECDemoDlg.cpp : implementation file
//

#include "mydefine.h"
//==========================================================================
//  创建socket
//  type =0  UDP   
//==========================================================================
SOCKET SocketCreate(char *mainIP,unsigned short mainPort,unsigned char type)
{
	WORD version ;
	WSADATA wsaData ;
	int nErr ;
	SOCKET MainSocket = NULL;
	
	//=====================================================================
	//注册SOCKET
	version = MAKEWORD(2, 0);
	nErr = WSAStartup(version, &wsaData);
	if (nErr)  return 0;

	//=====================================================================
	//创建Socket套接字
	SOCKADDR_IN sa_addr ;
	sa_addr.sin_family = AF_INET ;
	sa_addr.sin_port = htons(mainPort) ;         //绑定端口号
	sa_addr.sin_addr.s_addr = inet_addr(mainIP); //绑定IP地址

	if (type == MODE_UDP)
	{
		if((MainSocket = socket(AF_INET,SOCK_DGRAM,0)) == INVALID_SOCKET) return 0;  //UDP
	}
	else if (type == MODE_TCP)
	{
		if ((MainSocket = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET) return 0;  //TCP
	}

	unsigned long ON;
	ioctlsocket(MainSocket, FIONBIO, &ON);		//设置非阻塞模式
	//=====================================================================
	//绑定地址
	if(bind(MainSocket,(sockaddr *)&sa_addr,sizeof(SOCKADDR)) == SOCKET_ERROR) return 0 ;
	
	
	return MainSocket ;
}	
//===========================================================
//  侦听socket
unsigned char SocketListen(SOCKET MainSocket)
{	
	//监听客户端连接
	if(listen(MainSocket,1024) == SOCKET_ERROR) return 0 ;

	return 1 ;
}
//===========================================================================================
//  连接socket
unsigned char SocketConnect(SOCKET MainSocket,char *mainIP,unsigned short mainPort)
{	
	SOCKADDR_IN sa_addr ;
	
	sa_addr.sin_family = AF_INET ;
	sa_addr.sin_port = htons(mainPort) ;         //绑定端口号
	sa_addr.sin_addr.s_addr = inet_addr(mainIP); //绑定IP地址
	
	//客户端连接
	if(connect(MainSocket,(struct sockaddr *)&sa_addr,sizeof(struct sockaddr))== -1)  return 0 ;

	return 1 ;
}


//==========================================================================================================
//  发送函数
//==========================================================================================================
int SocketSendBuff(SOCKET nSocket,unsigned char type ,unsigned char *SBuff ,unsigned short nLen,SOCKADDR_IN ServerAddr)
{
	int sLen ;
	if (type == MODE_UDP)
	{
		sLen = sendto(nSocket,(char *)SBuff,nLen,0,(SOCKADDR*)&ServerAddr, sizeof(ServerAddr));
	}
	else if (type == MODE_TCP)
	{
		sLen = send(nSocket, (char *)SBuff, nLen, 0);
	}

	if (sLen == -1)
	{
		closesocket(nSocket);
		return -1;
	}

	return sLen ;
}

//==================================================================================================================
//  接收函数
//==================================================================================================================
int SocketRecvBuff(SOCKET nSocket, unsigned char type,  unsigned char *Buff, SOCKADDR_IN ServerAddr)
{
	unsigned char RecvBuff[2048];
	int i, nRecv = 0 ;
	int ServerLen = sizeof(ServerAddr);

	if (type == MODE_UDP)           			//UDP方式接收数据
	{
		nRecv = recvfrom(VariaDlg.LocalSocket, (char*)&RecvBuff, 1024, 0, (SOCKADDR*)&ServerAddr, &ServerLen);  //读取接收到的数据
		if (nRecv <= 0)	return 0;
	}
	else if (type == MODE_TCP)
	{
		nRecv = recv(nSocket, (char*)&RecvBuff, 2048, 0);
		if (nRecv <= 0)	return 0;
	}

	for (i = 0; i < nRecv; i++)
	{
		Buff[i] = RecvBuff[i];
	}

	
	return nRecv;
}

//===========================================================
//  获取本机IP地址
//===========================================================
unsigned char GetLocalIP(char *nIP)
{
	char tempBuff[17] = {0};
	char i,*ptr;

	WSADATA wsaData;
	char szHostName[MAX_PATH] = { 0 };
	int nRetCode;

	int err = WSAStartup(MAKEWORD(2, 0), &wsaData);
	if (err != 0)
	{
		return 0;
	}

	nRetCode = gethostname(szHostName, sizeof(szHostName));
	PHOSTENT hostinfo;

	if (nRetCode != 0)
	{
		WSACleanup();
		return 0;
	}

	hostinfo = gethostbyname(szHostName);
	ptr = inet_ntoa(*(struct in_addr*)*hostinfo->h_addr_list);

	for (i = 0; i < 16; i++)
	{
		nIP[i] = *ptr;
		ptr++;
	}

	WSACleanup();

	return 1;
}

//=============================================================================
// 绑定socket 的IP和端口号
//=============================================================================
void SocketConfig(SOCKADDR_IN *nSocket, char *ip, unsigned short port)
{
	nSocket->sin_family = AF_INET;
	nSocket->sin_port = htons(port);
	nSocket->sin_addr.s_addr = inet_addr(ip);
}


