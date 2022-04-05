#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <stdarg.h>

#ifdef PS4DEBUG

#define PORT 8888
#define MAX_DEBUG_MSG_LEN 100

#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#ifdef PS4
#include <orbis/libkernel.h>
#include <orbis/Sysmodule.h>
#endif

int connfd;
int sockfd;
socklen_t addrLen;

struct sockaddr_in serverAddr;
struct sockaddr_in clientAddr;

char debug_msg[MAX_DEBUG_MSG_LEN];

void init_ps4_debug() {

    // No buffering
    setvbuf(stdout, NULL, _IONBF, 0);

    // Create a server socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0)
    {
        for (;;);
    }

    // Bind to 0.0.0.0:PORT
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) != 0)
    {
        for (;;);
    }

    // Listen and accept clients
    addrLen = sizeof(clientAddr);

    if (listen(sockfd, 5) != 0)
    {
        for (;;);
    }

	connfd = accept(sockfd, (struct sockaddr*)&clientAddr, &addrLen);

	if (connfd < 0)
	{
		for (;;);
	}
}

void ps4_debug_printf(const char *restrict fmt, ...)
{
    va_list ap;
    va_start( ap, fmt );
	vdprintf(connfd, fmt, ap);
    va_end(ap);
}

#endif