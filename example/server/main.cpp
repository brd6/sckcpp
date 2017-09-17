//
// Created by brd6 on 17/09/17.
//

#include <cstdlib>
#include <sckcpp/Socket.hpp>
#include <iostream>

int tcp_main(int ac, char const **av)
{
  sckcpp::tcp::Socket tcpSocket;

  std::cout << "TCP socket created: " << tcpSocket.getSockAddress() << std::endl;
  std::cout << "Waiting for connection..." << std::endl;

  auto clientSocket = tcpSocket.accept();

  return EXIT_SUCCESS;
}

int main(int ac, char const **av)
{
  return tcp_main(ac, av);
}