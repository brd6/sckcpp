//
// Created by brd6 on 06/09/17.
//


#ifndef _SOCKETEXCEPTION_H_
# define _SOCKETEXCEPTION_H_

#include <string>
#include <exception>

namespace sckcpp
{
  class SocketException :
	  public std::exception
  {
   private:
    std::string mMsg;

   public:
    explicit SocketException(std::string const &msg) : mMsg(msg) {}

    /**
     * get the SocketException's message
     * @return const char*
     */
    const char* what() const throw() override { return mMsg.data(); }

  };
}

#endif /* !_SOCKETEXCEPTION_H_ */