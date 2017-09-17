//
// Created by brd6 on 17/09/17.
//

#include <sckcpp/Socket.hpp>

namespace sckcpp
{
  namespace tcp
  {
    Socket::Socket(SockAddress const &sockAddress, int backlog) :
      BaseSocket(SocketDomain::IP, SocketType::TCP, 0),
      mSockAddress(sockAddress)
    {
      bind();
    }

    Socket::Socket(SockAddress const &sockAddress) :
      mSockAddress(sockAddress)
    {

    }

    Socket::Socket(int port, int backlog) :
      mSockAddress("", port)
    {

    }

    Socket::~Socket()
    {

    }

    Socket Socket::accept()
    {
      return Socket();
    }
  }
}