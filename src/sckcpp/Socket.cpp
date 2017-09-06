//
// Created by bongol_b on 06/09/17.
//

#include <unistd.h>
#include <sys/socket.h>
#include <sckcpp/Socket.hpp>
#include <sckcpp/SocketException.hpp>

namespace sckcpp
{
  Socket::Socket() :
  	mFd(INVALID_SOCK_FD)
  {

  }

  Socket::Socket(int domain, int type, int protocol)
  {
    mFd = socket(domain, type, protocol);

    if (mFd < 0)
      throw SocketException("Unable to initialize the socket");
  }

  Socket::~Socket()
  {
    close();
  }

  int Socket::getFd() const
  {
    return mFd;
  }

  void Socket::close()
  {
    if (mFd == INVALID_SOCK_FD)
      return;

    ::close(mFd);
    mFd = INVALID_SOCK_FD;
  }

  void Socket::bind(const struct sockaddr *addr, socklen_t addrlen)
  {
    if (::bind(mFd, addr, addrlen) < 0)
      throw SocketException("address binding failed");
  }

  void Socket::connect(const struct sockaddr *addr, socklen_t addrlen)
  {
    if (::connect(mFd, addr, addrlen) < 0)
      throw SocketException("socket connection failed");
  }

  void Socket::listen(int backlog)
  {
    if (::listen(mFd, backlog) < 0)
      throw SocketException("listen setting failed");
  }

  Socket Socket::accept(struct sockaddr *addr, socklen_t *addrlen)
  {
    Socket clientSocket;

    clientSocket.mFd = ::accept(mFd, addr, addrlen);

    if (clientSocket.mFd < 0)
      throw SocketException("accept failed");

    return clientSocket;
  }

  void Socket::enableReuseAddr()
  {
    int optVal;
    int ret;

    optVal = 1;
    ret = setsockopt(mFd, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal));

    if (ret < 0)
      throw SocketException("Unable to set re use addr");
  }

}
