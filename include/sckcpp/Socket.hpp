//
// Created by brd6 on 17/09/17.
//

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <string>
#include <sckcpp/BaseSocket.hpp>
#include <sckcpp/SockAddress.hpp>

namespace sckcpp
{
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

  using static int DEFAULT_BACKLOG = 5;

  namespace tcp
  {
    class Socket :
      private BaseSocket
    {
    private:
      SockAddress mSockAddress;

    public:
      Socket(SockAddress const &sockAddress, int backlog = DEFAULT_BACKLOG);
      Socket(SockAddress const &sockAddress);
      Socket(int port = SockAddress::DEFAULT_PORT, int backlog = DEFAULT_BACKLOG);
      ~Socket();

      Socket accept();

    private:

    };
  }

  namespace udp
  {
    class Socket
    {
    public:
      Socket(std::string host, int port);
      ~Socket();

      bool
    };
  }
}

#endif /* !_SOCKET_H_ */