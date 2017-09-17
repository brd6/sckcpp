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

    }

    Socket::Socket(int port, int backlog) :
      Socket(SockAddress(port), sckcpp::DEFAULT_BACKLOG)
    {

    }

    Socket::Socket() :
      Socket(SockAddress(), sckcpp::DEFAULT_BACKLOG)
    {
    }

    Socket::~Socket()
    {

    }

//    Socket Socket::accept()
//    {
//      return Socket();
//    }
  }
}