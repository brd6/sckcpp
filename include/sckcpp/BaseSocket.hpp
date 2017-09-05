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
    TCP,
    UDP
  };

  enum SocketDomain
  {
    IP = AF_INET,
    IPV6 = AF_INET6,
    LOCAL_UNIX = AF_UNIX,
    LOCAL = AF_LOCAL
  };

  enum Network
  {
    
  };

  class BaseSocket
  {
   private:
    int mSockFd;

   protected:
    BaseSocket() = default;

   public:
    virtual ~BaseSocket() = default;
    BaseSocket(BaseSocket const &) = delete;
    BaseSocket &operator=(BaseSocket const &) = delete;

  };
}


#endif /* !_BaseSocket_H_ */