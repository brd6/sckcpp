//
// Created by brd6 on 06/09/17.
//


#ifndef _SocketException_H_
# define _SocketException_H_

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
     * @return
     */
    const char* what() const throw() override { return mMsg.data(); }

  };
}

#endif /* !_SocketException_H_ */