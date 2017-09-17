//
// Created by bongol_b on 17/09/17.
//

#include <sckcpp/Socket.hpp>

namespace sckcpp
{
  namespace tcp
  {
    Socket::Socket(std::string const &host, int port, int backlog) :
      BaseSocket(SocketDomain::IP, SocketType::TCP, 0)
    {
      bind();
    }

    Socket::Socket(std::string const &host, int port)
    {

    }

    Socket::Socket(int port, int backlog)
    {

    }

    Socket::~Socket()
    {

    }

    Socket Socket::accept()
    {
      return Socket();
    }
  }
}