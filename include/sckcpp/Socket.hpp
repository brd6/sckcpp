//
// Created by bongol_b on 17/09/17.
//

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <string>
#include <sckcpp/BaseSocket.hpp>

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

  using int DEFAULT_BACKLOG = 5;
  using int DEFAULT_PORT = 0;

  namespace tcp
  {
    class Socket :
      private BaseSocket
    {
    private:
      std::string mHost;
      int mPort;

    public:
      Socket(std::string const &host, int port, int backlog = DEFAULT_BACKLOG);
      Socket(std::string const &host, int port);
      Socket(int port = DEFAULT_PORT, int backlog = DEFAULT_BACKLOG);
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