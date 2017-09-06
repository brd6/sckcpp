//
// Created by brd6 on 06/09/17.
//

#include <bits/socket.h>

#ifndef _BASESOCKET_H_
# define _BASESOCKET_H_

namespace sckcpp
{
  enum SocketType
  {
    TCP = SOCK_STREAM,
    UDP = SOCK_DGRAM
  };

  enum SocketDomain
  {
    IP = AF_INET,
    IPV6 = AF_INET6,
    LOCAL_UNIX = AF_UNIX,
    LOCAL = AF_LOCAL
  };

  class Socket
  {
   public:
    const int INVALID_SOCK_FD = -1;

   private:
    int mFd;

   protected:
    Socket();

   public:
    Socket(int domain, int type, int protocol);
    virtual ~Socket();
    Socket(Socket const &) = delete;
    Socket &operator=(Socket const &) = delete;

    /**
     * Get the socket file descriptor
     * @return
     */
    int getFd() const;

    /**
     * Close the socket
     */
    void close();

    /**
     * assign an address to the socket
     * @param addr
     * @param addrlen
     */
    void bind(const struct sockaddr *addr, socklen_t addrlen);

    /**
     * Connect the socket to the addr specified
     * @param addr
     * @param addrlen
     */
    void connect(const struct sockaddr *addr, socklen_t addrlen);

    /**
     * Define the maximum pending connections for the socket
     * @param backlog
     */
    void listen(int backlog);

    /**
     * Accept a new connection on the socket and return the client socket when he's connected
     * @param addr
     * @param addrlen
     * @return
     */
    Socket accept(struct sockaddr *addr, socklen_t *addrlen);

  };
}


#endif /* !_BASESOCKET_H_ */