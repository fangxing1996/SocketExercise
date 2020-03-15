#include <sys/types.h>
#include <windows.h>
#include <stdio.h>
#include <winsock.h>
#include <Winsock2.h>
int main(){

	WORD sockVersion = MAKEWORD(2, 2);
	WSADATA wsaData;
	if (WSAStartup(sockVersion, &wsaData) != 0)
	{
		return 0;
	}
    SOCKET fd;
    fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (fd == INVALID_SOCKET)
	{
		printf("socket error !");
		return 0;
	}
    struct sockaddr_in sin;
	sin.sin_family = AF_INET;
	sin.sin_port = htons(8888);
	sin.sin_addr.S_un.S_addr = INADDR_ANY;
    if (bind(fd, (LPSOCKADDR)&sin, sizeof(sin)) == SOCKET_ERROR)
	{
		printf("bind error !");
	}
	if (listen(fd, 5) == SOCKET_ERROR)
	{
		printf("listen error !");
		return 0;
	}
	//循环接收数据
	SOCKET sClient;
	struct sockaddr_in remoteAddr;
	int nAddrlen = sizeof(remoteAddr);
	//char revData[255];
	printf("waiting...\n");
	sClient = accept(fd, (SOCKADDR *)&remoteAddr, &nAddrlen);
	if (sClient == INVALID_SOCKET)
	{
			printf("accept error !");
			exit(-1);
	}
	else
		printf("receive a connect: %s\n", inet_ntoa(remoteAddr.sin_addr));
	while (1){

		char revData[255];		
		//接收数据
		int ret = recv(sClient, revData, 255, 0);
		if (ret > 0)
		{
			revData[ret] = '\0';
			printf("%s", revData);
		}
		//发送数据
		char *sendData = "hello!\n";
		send(sClient, sendData, strlen(sendData), 0);
	}
	closesocket(sClient);
	closesocket(fd);
	return 0;
}
