//
// Created by brd6 on 17/09/17.
//

#ifndef _SOCKETPLATEFORM_H_
#define _SOCKETPLATEFORM_H_

#if _WIN32

#include <winsock2.h>
#pragma comment(lib, "wsock32.lib")

#else

#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <fcntl.h>

#endif

enum SocketType
{
  TCP = SOCK_STREAM,
  UDP = SOCK_DGRAM
};

enum SocketDomain
{
  IP = AF_INET,
  IPV6 = AF_INET6,
  LOCAL_UNIX = AF_UNIX,
  LOCAL = AF_LOCAL
};

#endif /* !_SOCKETPLATEFORM_H_ */