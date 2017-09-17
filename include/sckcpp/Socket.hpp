//
// Created by brd6 on 17/09/17.
//

#ifndef _SOCKET_H_
#define _SOCKET_H_

#include <string>
#include <sckcpp/BaseSocket.hpp>
#include <sckcpp/SockAddress.hpp>

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

      ~Socket() = default;

      /**
       * Accept a new connection on the socket and return the client socket when he's connected
       * @return Socket
       */
      Socket accept();

      /**
       * Connect the socket to the addr specified
       * @param sockAddress
       */
      void connect(SockAddress const &sockAddress);


      SockAddress const &getSockAddress() const;

    private:
      Socket(BaseSocket socket);
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