//
// Created by brd6 on 17/09/17.
//

#include <cstdlib>
#include <sckcpp/Socket.hpp>

int tcp_main(int ac, char const **av)
{
  sckcpp::tcp::Socket tcpSocket(sckcpp::SockAddress("localhost", 42));

  return EXIT_SUCCESS;
}

int main(int ac, char const **av)
{
  return tcp_main(ac, av);
}