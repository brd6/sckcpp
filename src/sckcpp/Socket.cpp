//
// Created by brd6 on 17/09/17.
//

#include <sckcpp/Socket.hpp>
#include <memory.h>

namespace sckcpp
{
  namespace tcp
  {
    Socket::Socket(SockAddress const &sockAddress, int backlog) :
      BaseSocket(SocketDomain::IP, SocketType::TCP, 0),
      mSockAddress(sockAddress),
      mCommunicationType(SocketCommunicationType::UNKNOWN),
      mBacklog(backlog)
    {
      enableReuseAddr();

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

    Socket::Socket(BaseSocket socket) :
        BaseSocket(socket)
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

    Socket Socket::accept()
    {
      if (mCommunicationType == SocketCommunicationType::UNKNOWN)
      {
        listen(mBacklog);
        mCommunicationType = SocketCommunicationType::SERVER;
      }

      sockaddr addr;
      socklen_t addrlen;

      Socket clientSocket = BaseSocket::accept(&addr, &addrlen);

      return clientSocket;
    }

    SockAddress const &Socket::getSockAddress() const
    {
      return mSockAddress;
    }

  }
}