//
// Created by brd6 on 17/09/17.
//

#ifndef _SOCKADDRESS_H_
#define _SOCKADDRESS_H_

#include <sckcpp/socketPlateform.hpp>
#include <string>

namespace sckcpp
{
  const int DEFAULT_PORT = 0;
  const SocketDomain DEFAULT_SOCKET_DOMAIN = SocketDomain::IP;
  const std::string DEFAULT_HOST = "localhost";

  class SockAddress
  {
  private:
    std::string mHost;
    int mPort;
    sockaddr_in mSockaddrIn;

  public:
    SockAddress(std::string const &host, int port = sckcpp::DEFAULT_PORT);
    explicit SockAddress(int port);
    SockAddress();
    ~SockAddress() = default;

    std::string const &getHost() const;

    int getPort() const;
    void setPort(int port);

    sockaddr_in const &getSockaddrIn() const;
    void setSockaddrIn(SocketDomain = DEFAULT_SOCKET_DOMAIN);

    sockaddr_in const &getSockAddrIn() const;

  private:
    in_addr resolveHostname();
  };
}

#endif /* !_SOCKADDRESS_H_ */