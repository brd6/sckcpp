//
// Created by brd6 on 17/09/17.
//

#ifndef _SOCKADDRESS_H_
#define _SOCKADDRESS_H_

#if _WIN32

#include <sckcpp/win/SockAddress.hpp>

#else

#include <sckcpp/unix/SockAddress.hpp>

#endif

#endif /* !_SOCKADDRESS_H_ */