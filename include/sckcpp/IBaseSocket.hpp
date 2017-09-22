//
// Created by brd6 on 06/09/17.
//

#include <sckcpp/socketPlateform.hpp>
#include <iostream>

#ifndef _BASESOCKET_H_
# define _BASESOCKET_H_

namespace sckcpp
{
  class IBaseSocket
  {
   protected:
    virtual IBaseSocket() = 0;
    virtual IBaseSocket(int domain, int type, int protocol) = 0;

  public:
    virtual int getFd() const = 0;
    virtual void close() = 0;
    virtual void bind(const sockaddr *addr, socklen_t addrlen) = 0;
    virtual void connect(const sockaddr *addr, socklen_t addrlen) = 0;
    virtual void listen(int backlog) = 0;
    virtual void accept(IBaseSocket &clientSocket,
                        sockaddr *addr,
                        socklen_t *addrlen) = 0;
    virtual void enableReuseAddr() = 0;
    virtual ssize_t send(const void *buf, size_t len, int flags) = 0;
    virtual ssize_t sendTo(const void *buf,
                           size_t len,
                           int flags,
                           const sockaddr *dest_addr,
                           socklen_t addrlen) = 0;
    virtual ssize_t receive(void *buf, size_t len, int flags) = 0;
    virtual ssize_t receiveFrom(void *buf,
                                size_t len,
                                int flags,
                                sockaddr *src_addr,
                                socklen_t *addrlen) = 0;
  };
}


#endif /* !_BASESOCKET_H_ */