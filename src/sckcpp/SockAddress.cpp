//
// Created by brd6 on 17/09/17.
//

#include <sckcpp/SockAddress.hpp>

namespace sckcpp
{

  SockAddress::SockAddress(std::string const &host, int port) :
    mHost(host),
    mPort(port)
  {

  }
}