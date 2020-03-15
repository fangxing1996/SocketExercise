#include <stdio.h>
#include <stdlib.h>
// #include <winsock2.h>
#include <windows.h>
// #pragma comment(lib,"ws2_32.lib")
int main(int argc, char* argv[])
{
	// WORD sockVersion = MAKEWORD(100, 200);
	// WSADATA data;
	// if (WSAStartup(sockVersion, &data) != 0)
	// {
	// 	return 0;
	// }
 
	SOCKET sclient = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sclient == INVALID_SOCKET)
	{
		printf("invalid socket !");
		return 0;
	}
 
	struct sockaddr_in serAddr;
	serAddr.sin_family = AF_INET;
	serAddr.sin_port = htons(8888);
	serAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	if (connect(sclient, (struct sockaddr *)&serAddr, sizeof(serAddr)) == SOCKET_ERROR)
	{
		printf("connect error !");
		closesocket(sclient);
		return 0;
	}
	for (int i = 0; i < 1000; i++)
	{
 
		char *sendData = "server i'm cient!\n";
		send(sclient, sendData, strlen(sendData), 0);
		char recData[255];
		int ret = recv(sclient, recData, 255, 0);
		if (ret > 0)
		{
	
			recData[ret] = '\0';	
			printf("%d%s", i, recData);
		}
		getchar();
	}
	closesocket(sclient);
	// WSACleanup();
	return 0;
}
