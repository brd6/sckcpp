//
// Created by brd6 on 17/09/17.
//

#ifndef _SOCKADDRESS_H_
#define _SOCKADDRESS_H_

#include <string>

namespace sckcpp
{
  class SockAddress
  {
  private:
    std::string mHost;
    int mPort;

  public:
    using static int DEFAULT_PORT = 0;

  public:
    SockAddress(std::string const &host, int port = DEFAULT_PORT);
  };
}

#endif /* !_SOCKADDRESS_H_ */