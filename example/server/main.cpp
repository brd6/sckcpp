//
// Created by brd6 on 17/09/17.
//

#include <unistd.h>

#include <cstdlib>
#include <sckcpp/Socket.hpp>
#include <iostream>
#include <memory.h>

int tcp_server_main(int ac, char const **av)
{
  sckcpp::tcp::Socket tcpSocket(sckcpp::SockAddress(4242));

  std::cout << "TCP socket created: " << tcpSocket.getSockAddress() << std::endl;
  std::cout << "Waiting for connection..." << std::endl;

  sckcpp::tcp::Socket clientSocket;

  tcpSocket.accept(clientSocket);

  std::cout << "New client: " << clientSocket.getSockAddress() << std::endl;

  // Send

  std::string msg("Hello from Server");
  sckcpp::Buffer buffer;

  buffer.data = (void *) msg.c_str();
  buffer.len = msg.size();

  clientSocket.send(buffer);

  // Receive
  sckcpp::Buffer bufferReceive;

  bufferReceive.data = new char[255];
  bufferReceive.len = 254;

  auto dataSize = clientSocket.receive(bufferReceive);

  ((char *)bufferReceive.data)[dataSize] = '\0';

  std::cout << "Server - From Client: '" << (char *)bufferReceive.data << "'" << std::endl;

  return EXIT_SUCCESS;
}

int udp_server_main(int ac, char const **av)
{
  return EXIT_SUCCESS;
}

int main(int ac, char const **av)
{
  return tcp_server_main(ac, av);
//  return udp_server_main(ac, av);
}