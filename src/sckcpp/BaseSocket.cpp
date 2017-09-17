//
// Created by brd6 on 06/09/17.
//

#include <unistd.h>
#include <sys/socket.h>
#include <sckcpp/BaseSocket.hpp>
#include <sckcpp/SocketException.hpp>
#include <cstring>

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
      throw SocketException(std::string("Unable to initialize the socket: ") +
                                std::strerror(errno));
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

  void BaseSocket::bind(const sockaddr *addr, socklen_t addrlen)
  {
    if (::bind(mFd, addr, addrlen) < 0)
      throw SocketException(std::string("address binding failed: ") + std::strerror(errno));
  }

  void BaseSocket::connect(const sockaddr *addr, socklen_t addrlen)
  {
    if (::connect(mFd, addr, addrlen) < 0)
      throw SocketException(std::string("socket connection failed: ") + std::strerror(errno));
  }

  void BaseSocket::listen(int backlog)
  {
    if (::listen(mFd, backlog) < 0)
      throw SocketException(std::string("listen setting failed: ") + std::strerror(errno));
  }

  BaseSocket BaseSocket::accept(sockaddr *addr, socklen_t *addrlen)
  {
    BaseSocket clientSocket;

    clientSocket.mFd = ::accept(mFd, addr, addrlen);

    if (clientSocket.mFd < 0)
      throw SocketException(std::string("accept failed: ") + std::strerror(errno));

    return clientSocket;
  }

  void BaseSocket::enableReuseAddr()
  {
    int optVal;
    int ret;

    optVal = 1;
    ret = setsockopt(mFd, SOL_SOCKET, SO_REUSEADDR, &optVal, sizeof(optVal));

    if (ret < 0)
      throw SocketException(std::string("Unable to set re use addr: ") + std::strerror(errno));
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
