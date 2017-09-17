//
// Created by brd6 on 17/09/17.
//

#include <sckcpp/Socket.hpp>
#include <iostream>

namespace sckcpp
{
  namespace tcp
  {
    Socket::Socket(SockAddress const &sockAddress, int backlog) :
      BaseSocket(SocketDomain::IP, SocketType::TCP, 0),
      mSockAddress(sockAddress)
    {
      mSockAddress.setSockaddrIn(SocketDomain::IP);

      bind(mSockAddress, sizeof(sockaddr_in));
      initializeAddressPortIfNeeded();
    }

    Socket::Socket(int port, int backlog) :
      Socket(SockAddress(port), sckcpp::DEFAULT_BACKLOG)
    {
    }

    Socket::Socket() :
      Socket(SockAddress())
    {
    }

    Socket::~Socket()
    {

    }

    void Socket::initializeAddressPortIfNeeded()
    {
      if (mSockAddress.getPort() > 0)
        return;

      sockaddr_in sin;
      int addrlen = sizeof(sin);

      if(getsockname(getFd(), (struct sockaddr *)&sin,
                     (socklen_t *) &addrlen) == 0)
        mSockAddress.setPort(ntohs(sin.sin_port));
    }

//    Socket Socket::accept()
//    {
//      return Socket();
//    }
  }
}