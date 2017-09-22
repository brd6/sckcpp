//
// Created by brd6 on 17/09/17.
//

#ifndef _SOCKETPLATEFORM_H_
#define _SOCKETPLATEFORM_H_

#if _WIN32

#include <sckcpp/win/socketPlateform.hpp>

#else

#include <sckcpp/unix/socketPlateform.hpp>

#endif

#endif /* !_SOCKETPLATEFORM_H_ */