//
// Created by brd6 on 17/09/17.
//

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <string>
#include <sckcpp/BaseSocket.hpp>
#include <sckcpp/SockAddress.hpp>
#include <sckcpp/Buffer.hpp>
#include <iostream>

namespace sckcpp
{
  const int DEFAULT_BACKLOG = 5;

  namespace tcp
  {
    class Socket :
      private BaseSocket
    {
    private:
      SockAddress mSockAddress;
      SocketCommunicationType mCommunicationType;
      int mBacklog;

    public:
      /**
       * Socket initialisation
       * @param sockAddress
       * @param backlog
       */
      Socket(SockAddress const &sockAddress, int backlog = sckcpp::DEFAULT_BACKLOG);

      /**
       * Socket initialisation
       * @param port
       * @param backlog
       */
      Socket(int port, int backlog = sckcpp::DEFAULT_BACKLOG);

      /**
       * Socket initialisation
       */
      Socket();

      ~Socket()
      {
	std::cout << "Socket::dtr" << std::endl;
      }

      /**
       * Accept a new connection on the socket and return the client socket when he's connected
       * @return Socket
       */
      void accept(Socket &clientSocket);

      /**
       * Connect the socket to the addr specified
       * @param sockAddress
       */
      void connect(SockAddress const &sockAddress);

      /**
       * Return the SockAddress of this socket
       * @return
       */
      SockAddress const &getSockAddress() const;

      /**
       * Send data to the socket
       * @param buffer
       * @param flags
       * @return
       */
      ssize_t send(Buffer const &buffer, int flags = 0);

      /**
       * Receive data from sender's socket
       * @param buf
       * @param len
       * @param flags
       * @return
       */
      ssize_t receive(Buffer &buffer, int flags = 0);

      /**
       * Close the socket
       */
      void close() override ;

      int getFd() const { return mFd; }

    private:
      explicit Socket(BaseSocket socket);
      void initializeAddressPortIfNeeded();

    };
  }

  namespace udp
  {
    class Socket
    {
//    public:
//      Socket(std::string host, int port);
//      ~Socket();
    };
  }
}

#endif /* !_SOCKET_H_ */