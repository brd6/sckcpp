//
// Created by bongol_b on 06/09/17.
//

#include <unistd.h>
#include <sys/socket.h>
#include <sckcpp/BaseSocket.hpp>
#include <sckcpp/SocketException.hpp>

namespace sckcpp
{
  BaseSocket::BaseSocket() :
  	mFd(INVALID_SOCK_FD)
  {

  }

  BaseSocket::BaseSocket(int domain, int type, int protocol)
  {
    mFd = socket(domain, type, protocol);

    if (mFd < 0)
      throw SocketException("Unable to initialize the socket");
  }

  BaseSocket::~BaseSocket()
  {
    close();
  }

  int BaseSocket::getFd() const
  {
    return mFd;
  }

  void BaseSocket::close()
  {
    if (mFd == INVALID_SOCK_FD)
      return;

    ::close(mFd);
    mFd = INVALID_SOCK_FD;
  }

  void BaseSocket::bind(const struct sockaddr *addr, socklen_t addrlen)
  {
    if (::bind(mFd, addr, addrlen) < 0)
      throw SocketException("address binding failed");
  }

  void BaseSocket::connect(const struct sockaddr *addr, socklen_t addrlen)
  {
    if (::connect(mFd, addr, addrlen) < 0)
      throw SocketException("socket connection failed");
  }

  void BaseSocket::listen(int backlog)
  {
    if (::listen(mFd, backlog) < 0)
      throw SocketException("listen setting failed");
  }

  BaseSocket BaseSocket::accept(struct sockaddr *addr, socklen_t *addrlen)
  {
    BaseSocket clientSocket;

    clientSocket.mFd = ::accept(mFd, addr, addrlen);

    if (clientSocket.mFd < 0)
      throw SocketException("accept failed");

    return clientSocket;
  }

  void BaseSocket::enableReuseAddr()
  {
    int optVal;
    int ret;

    optVal = 1;
    ret = setsockopt(mFd, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal));

    if (ret < 0)
      throw SocketException("Unable to set re use addr");
  }

  ssize_t BaseSocket::send(const void *buf, size_t len, int flags)
  {
    return ::send(mFd, buf, len, flags);
  }

  ssize_t BaseSocket::sendTo(const void *buf, size_t len, int flags,
			 const struct sockaddr *dest_addr, socklen_t addrlen)
  {
    return ::sendto(mFd, buf, len, flags, dest_addr, addrlen);
  }

  ssize_t BaseSocket::receive(void *buf, size_t len, int flags)
  {
    return ::recv(mFd, buf, len, flags);
  }

  ssize_t BaseSocket::receiveFrom(void *buf, size_t len, int flags,
			      struct sockaddr *src_addr, socklen_t *addrlen)
  {
    return ::recvfrom(mFd, buf, len, flags, src_addr, addrlen);
  }

}
