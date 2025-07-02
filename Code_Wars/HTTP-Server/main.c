//We included this macro, Because if we needed to include Windows.h header file
             //and we can't do that because there's a library in Windows.h header file is winsock.h which will conflict
                                        //with our winsock2.h file because they have some of the function shared between the two


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <mswsock.h>

#pragma comment(lib,"Ws2_32.lib")
#define PORT 8080
#define MAX 150

#define MY_PRINT(x) _Generic((x),\
    int: x * 5,\
    default: x * 5.5\
    )
/*

int intializeServer(int connet,SOCKET server)
{
    WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	SOCKET s = socket(AF_INET, SOCK_STREAM, 0);
	struct sockaddr_in*addr;
	addr->sin_family = AF_INET;
	addr->sin_addr.s_addr = 0;
	addr->sin_port = htons(8080);
	bind(s, *(&addr), sizeof(addr)); //error to check
    listen(s, 10);
    SOCKET client = accept(s,0,0);
    char request[256] = {0};
    recv(client, request, 256,0);
    if (memcmp(request, "GET / ", 6) == 0)
    {
        FILE* f = fopen("error.html", "r");
        char buffer1[256] = {0};
        fread(buffer1,1,256,f);
        send(client, buffer1, 256, 0);
    }
}




*/


int main(void)
{
    char c1[] = "mina";
    char c2[] = {'m', 'i', 'n', 'a' };
    int s1 = sizeof(c1) / sizeof(c1[0]);
    int s2 = sizeof(c2) / sizeof(c2[0]);
    int arr[] = {1,2,3,4};
    printf("%d      %d",*arr, arr);
    return 0;
}



/*

    int unwantedSockets[] = {1039,2034,8950,1130},fconnect,buffer[MAX],n = 0,nSet = sizeof(unwantedSockets) / sizeof(unwantedSockets[0]);
    struct sockaddr_in setSocketAddr;

    struct hostent* localHost;
    ADDRINFOA adder;
    PADDRINFOA *result;
    char* localIP;
    fconnect = WSAStartup(MAKEWORD(2,2), &wsaData);
    fd_set *setServer;
    setServer->fd_count = 4;
    setServer->fd_array[nSet];
    memcpy(setServer->fd_array,unwantedSockets,nSet*sizeof(unwantedSockets[0]));

    if(fconnect != 0)
    {
        printf_s("WSAStartup falied: %d\n",fconnect);
        return 1;
    }

    if(LOBYTE(wsaData.wVersion) != 2 || HIBYTE(wsaData.wVersion) != 2 || __WSAFDIsSet(server,setServer) != 0)
    {
            WSACleanup( );
            return 1;
    }


    SOCKET mySocket_ip4 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    SOCKET mySocket_ip6 = socket(AF_INET6, SOCK_STREAM, IPPROTO_TCP);
        adder.ai_addrlen = 0;
    adder.ai_canonname = NULL;
    adder.ai_addr = NULL;
    adder.ai_next = NULL;
    adder.ai_flags = AI_PASSIVE;
    adder.ai_family = AF_INET;
    adder.ai_socktype = SOCK_STREAM;
    adder.ai_protocol = IPPROTO_TCP;


*/
