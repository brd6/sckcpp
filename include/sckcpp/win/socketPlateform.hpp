//
// Created by brd6 on 17/09/17.
//

#ifndef _WIN_SOCKETPLATEFORM_H_
#define _WIN_SOCKETPLATEFORM_H_

#include <winsock.h>

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
  LOCAL = AF_UNIX
};

enum SocketCommunicationType
{
  SERVER,
  CLIENT,
  UNKNOWN
};

#endif /* !_WIN_SOCKETPLATEFORM_H_ */