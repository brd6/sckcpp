//
// Created by brd6 on 17/09/17.
//

#ifndef _UNIX_SOCKETPLATEFORM_H_
#define _UNIX_SOCKETPLATEFORM_H_

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

enum SocketCommunicationType
{
  SERVER,
  CLIENT,
  UNKNOWN
};

#endif /* !_UNIX_SOCKETPLATEFORM_H_ */