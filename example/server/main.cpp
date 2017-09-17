//
// Created by brd6 on 17/09/17.
//

#include <cstdlib>
#include <sckcpp/Socket.hpp>
#include <iostream>
#include <memory.h>

int tcp_main(int ac, char const **av)
{
  sckcpp::tcp::Socket tcpSocket;

  std::cout << "TCP socket created: " << tcpSocket.getSockAddress() << std::endl;
  std::cout << "Waiting for connection..." << std::endl;

  auto clientSocket = tcpSocket.accept();

  std::cout << "New client!" << std::endl;


//  sckcpp::BaseSocket baseSocket(AF_INET, SOCK_STREAM, 0);
//
//  struct sockaddr_in cliAddr, servAddr;
//  int cliLen;
//
//  bzero((char *)&servAddr, sizeof(servAddr));
//  servAddr.sin_family = AF_INET;
//  servAddr.sin_addr.s_addr = INADDR_ANY;
//  servAddr.sin_port = htons(4243);
//
//  baseSocket.enableReuseAddr();
//
//  baseSocket.bind((struct sockaddr *) &servAddr, sizeof(servAddr));
//  baseSocket.listen(5);
//
//  while (1)
//  {
//    auto clientSocket = baseSocket.accept(nullptr, nullptr);
//
//    std::cout << "New client!" << std::endl;
//  }

  return EXIT_SUCCESS;
}

int main(int ac, char const **av)
{
  return tcp_main(ac, av);
}