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

    std::string msg("Hello world!\n");
    sckcpp::Buffer buffer;

    buffer.data = (void *) msg.c_str();
    buffer.len = msg.size();

    std::cout << clientSocket.send(buffer) << std::endl;

    std::cout << "New client: " << clientSocket.getSockAddress() << std::endl;

    sckcpp::Buffer bufferReceive;

    bufferReceive.data = malloc(255);
    bufferReceive.len = 254;

    std::cout << tcpSocket.receive(bufferReceive) << std::endl;

    std::cout << "Receive: " << (char *)bufferReceive.data << std::endl;

    break;
  }

  return EXIT_SUCCESS;
}

int main(int ac, char const **av)
{
  return tcp_main(ac, av);
}