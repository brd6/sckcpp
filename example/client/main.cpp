//
// Created by brd6 on 17/09/17.
//

#include <unistd.h>

#include <cstdlib>
#include <sckcpp/Socket.hpp>
#include <iostream>
#include <memory.h>

int tcp_client_main(int ac, char const **av)
{
  sckcpp::tcp::Socket tcpSocket;

  std::cout << "TCP socket created: " << tcpSocket.getSockAddress() << std::endl;

  tcpSocket.connect(sckcpp::SockAddress(4242));

  std::cout << "OKOKO" << std::endl;


  // Send
  sckcpp::Buffer bufferSend;

  auto strHello = std::string("Hello from Client");

  bufferSend.data = (void *)strHello.c_str();
  bufferSend.len = strHello.length();

  tcpSocket.send(bufferSend);

  // Receive
  sckcpp::Buffer bufferReceive;

  bufferReceive.data = new char[255];
  bufferReceive.len = 254;

  auto dataSize = tcpSocket.receive(bufferReceive);

  ((char *)bufferReceive.data)[dataSize] = '\0';

  std::cout << "Client - From Server: '" << (char *)bufferReceive.data << "'" << std::endl;

  return EXIT_SUCCESS;
}

int udp_client_main(int ac, char const **av)
{
  sckcpp::udp::Socket udpSocket;

  std::cout << "UDP socket created: " << udpSocket.getSockAddress() << std::endl;

  sckcpp::SockAddress serverAddress(4242);

  // Send
  sckcpp::Buffer bufferSend;

  auto strHello = std::string("Hello from Client");

  bufferSend.data = (void *) strHello.c_str();
  bufferSend.len = strHello.length();

  udpSocket.send(serverAddress, bufferSend);

  // Receive
  sckcpp::Buffer bufferReceive;

  bufferReceive.data = new char[255];
  bufferReceive.len = 254;

  udpSocket.receive(serverAddress, bufferReceive);

  std::cout << "Client - Receive: '" << (char *)bufferReceive.data << "' from " << serverAddress << std::endl;


  return EXIT_SUCCESS;
}

int main(int ac, char const **av)
{
  return tcp_client_main(ac, av);
//  return udp_client_main(ac, av);
}