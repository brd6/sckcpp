//
// Created by brd6 on 17/09/17.
//

#include <sckcpp/Socket.hpp>
#include <zconf.h>

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

      sockaddr_in sin{};
      int addrlen = sizeof(sin);

      if(getsockname(getFd(), (sockaddr *)&sin,
                     (socklen_t *) &addrlen) == 0)
        mSockAddress.setPort(ntohs(sin.sin_port));
    }

    void Socket::accept(Socket &clientSocket)
    {
      sockaddr addr{};
      socklen_t addrlen;

      if (mCommunicationType == SocketCommunicationType::UNKNOWN)
      {
        listen(mBacklog);
        mCommunicationType = SocketCommunicationType::SERVER;
      }

      BaseSocket::accept(clientSocket, &addr, &addrlen);

      auto *sockaddrIn = (sockaddr_in*)&addr;
      clientSocket.mSockAddress.setSockaddrIn(*sockaddrIn);
    }

    SockAddress const &Socket::getSockAddress() const
    {
      return mSockAddress;
    }

    void Socket::connect(SockAddress const &sockAddress)
    {
      if (mCommunicationType == SocketCommunicationType::UNKNOWN)
        mCommunicationType = SocketCommunicationType::CLIENT;

      BaseSocket::connect(sockAddress, sizeof(sockaddr_in));
    }

    ssize_t Socket::send(Buffer const &buffer, int flags)
    {
      return BaseSocket::send(buffer.data, buffer.len, flags);
    }

    void Socket::close()
    {
      BaseSocket::close();
    }

    ssize_t Socket::receive(Buffer &buffer, int flags)
    {
      return BaseSocket::receive(buffer.data, buffer.len, flags);
    }
  }

  namespace udp
  {

    Socket::Socket(SockAddress const &sockAddress) :
	    BaseSocket(SocketDomain::IP, SocketType::UDP, 0),
	    mSockAddress(sockAddress),
	    mCommunicationType(SocketCommunicationType::SERVER)
    {
      enableReuseAddr();

      mSockAddress.setSockaddrIn(SocketDomain::IP);

      bind(mSockAddress, sizeof(sockaddr_in));

      initializeAddressPortIfNeeded();

    }

    Socket::Socket(int port) :
    	Socket(SockAddress(port))
    {

    }

    Socket::Socket() :
	    BaseSocket(SocketDomain::IP, SocketType::UDP, 0),
	    mCommunicationType(SocketCommunicationType::CLIENT)
    {
      enableReuseAddr();
    }

    SockAddress const &Socket::getSockAddress() const
    {
      return mSockAddress;
    }

    void Socket::close()
    {
      BaseSocket::close();
    }

    void Socket::initializeAddressPortIfNeeded()
    {
      if (mSockAddress.getPort() > 0)
	return;

      sockaddr_in sin{};
      int addrlen = sizeof(sin);

      if(getsockname(getFd(), (sockaddr *)&sin,
		     (socklen_t *) &addrlen) == 0)
	mSockAddress.setPort(ntohs(sin.sin_port));
    }

    ssize_t Socket::send(SockAddress const &receiverAddress,
			 Buffer const &buffer,
			 int flags)
    {
      return BaseSocket::sendTo(buffer.data,
				buffer.len,
				flags,
				receiverAddress,
				sizeof(sockaddr_in));
    }

    ssize_t Socket::receive(SockAddress &senderAddress,
			    Buffer &buffer,
			    int flags)
    {
      socklen_t sockLen = sizeof(sockaddr_in);

      auto revSize = BaseSocket::receiveFrom(buffer.data,
				     buffer.len,
				     flags,
				     senderAddress,
				     &sockLen);

      senderAddress.updateAddressInfo();
      return revSize;
    }
  }

}