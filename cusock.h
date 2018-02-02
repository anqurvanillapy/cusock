#ifndef _CUSOCK_H
#define _CUSOCK_H

#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

typedef struct cu_handle_t {
	struct sockaddr_in addr;
	int sockfd;
} cu_handle_t;

cu_handle_t* cusock(const char* addr, uint16_t port);

#endif /* !_CUSOCK_H */
