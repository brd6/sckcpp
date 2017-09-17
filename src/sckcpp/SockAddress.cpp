//
// Created by brd6 on 17/09/17.
//

#include <sckcpp/SockAddress.hpp>
#include <cstring>
#include <sckcpp/SocketException.hpp>
#include <iostream>

namespace sckcpp
{

  SockAddress::SockAddress(std::string const &host, int port) :
    mHost(host),
    mPort(port)
  {
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
    mSockaddrIn.sin_addr.s_addr = resolveHostname();
    mSockaddrIn.sin_port = htons(4244);

//    mSockaddrIn.sin_family = socketDomain;
//    mSockaddrIn.sin_addr.s_addr = htonl(INADDR_ANY);
//    mSockaddrIn.sin_port = htons(4244);
  }

  in_addr_t SockAddress::resolveHostname()
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

  std::ostream &operator<<(std::ostream &os, SockAddress const &obj)
  {
    os << obj.getHost() << std::string(":") << std::to_string(obj.getPort());

    return os;
  }
}