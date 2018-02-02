#include "cusock.h"

static int _IS_INIT = 0;

static int
_cu_init()
{
	if (_IS_INIT) return 1;
	return _IS_INIT = !_IS_INIT;
}

cu_handle_t*
cusock(const char* addr, uint16_t port)
{
	cu_handle_t* h;

	if (!_cu_init()) return NULL;

	h = (cu_handle_t*)malloc(sizeof(cu_handle_t));
	memset(h, 0, sizeof(cu_handle_t));
	h->addr.sin_family      = AF_INET;
	h->addr.sin_port        = htons(port);
	h->addr.sin_addr.s_addr = inet_addr(addr);
	h->sockfd               = socket(AF_INET, SOCK_DGRAM, 0);

	return h;
}
