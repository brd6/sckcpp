//
// Created by brd6 on 17/09/17.
//

#include <unistd.h>

#include <cstdlib>
#include <sckcpp/Socket.hpp>
#include <iostream>
#include <memory.h>

int tcp_main(int ac, char const **av)
{
  sckcpp::tcp::Socket tcpSocket(sckcpp::SockAddress(4242));

  std::cout << "TCP socket created: " << tcpSocket.getSockAddress() << std::endl;
  std::cout << "Waiting for connection..." << std::endl;

  sckcpp::tcp::Socket clientSocket;

  tcpSocket.accept(clientSocket);

  sckcpp::Buffer bufferReceive;

  bufferReceive.data = malloc(255);
  bufferReceive.len = 254;

//  while (true)
//  {
//    std::string msg("Hello world!\n");
//    sckcpp::Buffer buffer;
//
//    buffer.data = (void *) msg.c_str();
//    buffer.len = msg.size();
//
//    std::cout << clientSocket.send(buffer) << std::endl;
//
//    std::cout << "New client: " << clientSocket.getSockAddress() << std::endl;

//  std::cout << "read: " << read(clientSocket.getFd(), bufferReceive.data, bufferReceive.len) << std::endl;
//
    std::cout << clientSocket.receive(bufferReceive) << std::endl;

    std::cout << "Receive: '" << (char *)bufferReceive.data << "'" << std::endl;

//    break;
//  }

  return EXIT_SUCCESS;
}

int main(int ac, char const **av)
{
  return tcp_main(ac, av);
}