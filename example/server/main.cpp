//
// Created by brd6 on 17/09/17.
//

#include <cstdlib>
#include <sckcpp/Socket.hpp>
#include <iostream>
#include <memory.h>

int tcp_main(int ac, char const **av)
{
  sckcpp::tcp::Socket tcpSocket(sckcpp::SockAddress(4242));

  std::cout << "TCP socket created: " << tcpSocket.getSockAddress() << std::endl;
  std::cout << "Waiting for connection..." << std::endl;

  while (1)
  {
    auto clientSocket = tcpSocket.accept();

    std::cout << "New client: " << clientSocket.getSockAddress() << std::endl;
  }

  return EXIT_SUCCESS;
}

int main(int ac, char const **av)
{
  return tcp_main(ac, av);
}