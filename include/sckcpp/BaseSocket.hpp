//
// Created by brd6 on 06/09/17.
//

#ifndef _BASESOCKET_H_
# define _BASESOCKET_H_

#if _WIN32

#include <sckcpp/win/BaseSocket.hpp>

#else

#include <sckcpp/unix/BaseSocket.hpp>

#endif

#endif /* !_BASESOCKET_H_ */