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
  const int DEFAULT_BACKLOG = 5;

  namespace tcp
  {
    class Socket :
      private BaseSocket
    {
    private:
      SockAddress mSockAddress;

    public:
      Socket(SockAddress const &sockAddress, int backlog = sckcpp::DEFAULT_BACKLOG);
      Socket(int port, int backlog = sckcpp::DEFAULT_BACKLOG);
      Socket();
      ~Socket();

//      Socket accept();

    private:

    };
  }

  namespace udp
  {
    class Socket
    {
//    public:
//      Socket(std::string host, int port);
//      ~Socket();
    };
  }
}

#endif /* !_SOCKET_H_ */