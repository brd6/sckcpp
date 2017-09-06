//
// Created by brd6 on 06/09/17.
//

#include <bits/socket.h>

#ifndef BaseSocket_H_
# define _BaseSocket_H_

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

  class BaseSocket
  {
   private:
    int mfd;

   protected:
    BaseSocket(int domain, int type, int protocol);

   public:
    virtual ~BaseSocket() = default;
    BaseSocket(BaseSocket const &) = delete;
    BaseSocket &operator=(BaseSocket const &) = delete;

    int getFd() const;
    void close();

  };
}


#endif /* !_BaseSocket_H_ */