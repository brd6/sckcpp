//
// Created by brd6 on 06/09/17.
//

#include <sckcpp/socketPlateform.hpp>

#ifndef _BASESOCKET_H_
# define _BASESOCKET_H_

namespace sckcpp
{
  class BaseSocket
  {
   public:
    const int INVALID_SOCK_FD = -1;

   private:
    int mFd;

   protected:
    BaseSocket();
    BaseSocket(int domain, int type, int protocol);

  public:
    virtual ~BaseSocket();

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
    BaseSocket accept(struct sockaddr *addr, socklen_t *addrlen);

    /**
     * Enable the possibility to reuse the socket address after server closing
     */
    void enableReuseAddr();

    /**
     * 
     * @param buf
     * @param len
     * @param flags
     * @return
     */
    ssize_t send(const void *buf, size_t len, int flags);

    /**
     *
     * @param buf
     * @param len
     * @param flags
     * @param dest_addr
     * @param addrlen
     * @return
     */
    ssize_t sendTo(const void *buf,
       size_t len,
       int flags,
       const struct sockaddr *dest_addr,
       socklen_t addrlen);

    /**
     *
     * @param buf
     * @param len
     * @param flags
     * @return
     */
    ssize_t receive(void *buf, size_t len, int flags);

    /**
     *
     * @param buf
     * @param len
     * @param flags
     * @param src_addr
     * @param addrlen
     * @return
     */
    ssize_t receiveFrom(void *buf,
      size_t len,
      int flags,
      struct sockaddr *src_addr,
      socklen_t *addrlen);
  };
}


#endif /* !_BASESOCKET_H_ */