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
      explicit Socket(SockAddress const &sockAddress,
		      int backlog = sckcpp::DEFAULT_BACKLOG);

      /**
       * Socket initialisation
       * @param port
       * @param backlog
       */
      explicit Socket(int port, int backlog = sckcpp::DEFAULT_BACKLOG);

      /**
       * Socket initialisation
       */
      Socket();

      /**
       * Accept a new connection on the socket and return the client
       * socket when he's connected
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
       * @param buffer
       * @param flags
       * @return
       */
      ssize_t receive(Buffer &buffer, int flags = 0);

      /**
       * Close the socket
       */
      void close() override ;

    private:
      explicit Socket(BaseSocket socket);
      void initializeAddressPortIfNeeded();

    };
  }

  namespace udp
  {
    class Socket :
	    private BaseSocket
    {
     private:
      SockAddress mSockAddress;
      SocketCommunicationType mCommunicationType;

    public:
      /**
       * Socket initialisation
       * @param sockAddress
       */
      explicit Socket(SockAddress const &sockAddress);

      /**
       * Socket initialisation
       * @param port
       */
      explicit Socket(int port);

      /**
       * Socket initialisation
       */
      Socket();

      /**
       * eturn the SockAddress of this socket
       * @return
       */
      SockAddress const &getSockAddress() const;

      /**
       * Send data to the socket
       * @param buffer
       * @param flags
       * @return
       */
      ssize_t send(SockAddress const &receiverAddress,
		   Buffer const &buffer,
		   int flags = 0);

      /**
       * Receive data from sender's socket
       * @param buffer
       * @param flags
       * @return
       */
      ssize_t receive(SockAddress &senderAddress,
		      Buffer &buffer,
		      int flags = 0);

      /**
       * Close the socket
       */
      void close() override ;

     private:
      void initializeAddressPortIfNeeded();

    };
  }
}

#endif /* !_SOCKET_H_ */