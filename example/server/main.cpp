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
  sckcpp::tcp::Socket tcpSocket(4242);

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
  sckcpp::udp::Socket udpSocket(4242);

  std::cout << "UDP socket created: " << udpSocket.getSockAddress() << std::endl;

  sckcpp::SockAddress clientAddress;

  // Receive
  sckcpp::Buffer bufferReceive;

  bufferReceive.data = new char[255];
  bufferReceive.len = 254;

  udpSocket.receive(clientAddress, bufferReceive);

  std::cout << "Server - Receive: '" << (char *)bufferReceive.data << "' from " << clientAddress << std::endl;

  // Send
  sckcpp::Buffer bufferSend;

  auto strHello = std::string("Hello from Server");
  bufferSend.data = (void *) strHello.c_str();
  bufferSend.len = strHello.length();

  udpSocket.send(clientAddress, bufferSend);

  return EXIT_SUCCESS;
}

int main(int ac, char const **av)
{
  return tcp_server_main(ac, av);
//  return udp_server_main(ac, av);
}