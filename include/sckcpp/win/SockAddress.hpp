//
// Created by brd6 on 17/09/17.
//

#ifndef _WIN_SOCKADDRESS_H_
#define _WIN_SOCKADDRESS_H_

#include <string>
#include <sckcpp/socketPlateform.hpp>
#include <winsock.h>

namespace sckcpp
{
  const int DEFAULT_PORT = 0;
  const SocketDomain DEFAULT_SOCKET_DOMAIN = SocketDomain::IP;
  const std::string DEFAULT_HOST{};

  class SockAddress
  {
  private:
    std::string mHost;
    int mPort;
    sockaddr_in mSockaddrIn;

  public:
    explicit SockAddress(std::string const &host, int port = sckcpp::DEFAULT_PORT, SocketDomain socketDomain = DEFAULT_SOCKET_DOMAIN);

    explicit SockAddress(int port);
    SockAddress();
    ~SockAddress() = default;

    std::string const &getHost() const;
    void setHost(std::string const &host);

    int getPort() const;
    void setPort(int port);

    sockaddr_in const &getSockaddrIn() const;
    void setSockaddrIn(SocketDomain = DEFAULT_SOCKET_DOMAIN);
    void setSockaddrIn(sockaddr_in const &sockaddrIn);

    operator const sockaddr*() const
    {
      return (const sockaddr *)(&mSockaddrIn);
    }

    operator sockaddr*() const
    {
      return (sockaddr *)(&mSockaddrIn);
    }

    void updateAddressInfo();

   private:
    u_long resolveSockAddrInSAddr();
    void updateAddressInfo(sockaddr_in const &sockaddrIn);

  };

  std::ostream &operator<<(std::ostream &out, const SockAddress &obj);
}

#endif /* !_WIN_SOCKADDRESS_H_ */