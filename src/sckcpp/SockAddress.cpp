//
// Created by brd6 on 17/09/17.
//

#include <sckcpp/SockAddress.hpp>
#include <cstring>
#include <sckcpp/SocketException.hpp>
#include <iostream>

namespace sckcpp
{

  SockAddress::SockAddress(std::string const &host, int port, SocketDomain socketDomain) :
    mHost(host),
    mPort(port)
  {
    setSockaddrIn(socketDomain);
  }

  SockAddress::SockAddress(int port) :
      SockAddress(sckcpp::DEFAULT_HOST, port)
  {
  }

  SockAddress::SockAddress() :
      SockAddress(sckcpp::DEFAULT_HOST, sckcpp::DEFAULT_PORT)
  {

  }

  std::string const &SockAddress::getHost() const
  {
    return mHost;
  }

  int SockAddress::getPort() const
  {
    return mPort;
  }

  sockaddr_in const &SockAddress::getSockaddrIn() const
  {
    return mSockaddrIn;
  }

  void SockAddress::setSockaddrIn(SocketDomain socketDomain)
  {
    std::memset(&mSockaddrIn, 0, sizeof(mSockaddrIn));

    mSockaddrIn.sin_family = socketDomain;
    mSockaddrIn.sin_addr.s_addr = resolveSockAddrInSAddr();
    mSockaddrIn.sin_port = htons(mPort);

    if (mHost.empty())
      updateAddressInfo(mSockaddrIn);
  }

  in_addr_t SockAddress::resolveSockAddrInSAddr()
  {
    if (mHost.empty())
      return htonl(INADDR_ANY);

    hostent *host;

    host = gethostbyname(mHost.c_str());

    if (host == nullptr)
      throw SocketException("Unable to resolve the hostname '" + mHost + "'");

    return (*((in_addr *) host->h_addr_list[0])).s_addr;
  }

  void SockAddress::setPort(int port)
  {
    mPort = port;
  }

  void SockAddress::setSockaddrIn(sockaddr_in const &sockaddrIn)
  {
    std::memcpy(&mSockaddrIn, &sockaddrIn, sizeof(sockaddrIn));

    updateAddressInfo(mSockaddrIn);
  }

  void SockAddress::updateAddressInfo(sockaddr_in const &sockaddrIn)
  {
    mHost = inet_ntoa(((sockaddr_in *)&sockaddrIn)->sin_addr);

    if (mPort <= 0)
      mPort = sockaddrIn.sin_port;
  }

  void SockAddress::updateAddressInfo()
  {
    mHost = inet_ntoa((&mSockaddrIn)->sin_addr);

    if (mPort <= 0)
      mPort = mSockaddrIn.sin_port;
  }

  void SockAddress::setHost(std::string const &host)
  {
    mHost = host;
  }

  std::ostream &operator<<(std::ostream &os, SockAddress const &obj)
  {
    os << obj.getHost() << std::string(":") << std::to_string(obj.getPort());

    return os;
  }
}