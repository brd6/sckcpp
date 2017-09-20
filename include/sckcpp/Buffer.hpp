//
// Created by brd6 on 17/09/17.
//

#ifndef _BUFFER_H_
#define _BUFFER_H_

namespace sckcpp
{
  struct Buffer
  {
    void *data;
    size_t len{};

    explicit Buffer(void *data = nullptr, size_t len = 0) : data(data), len(len) {}
  };
}

#endif /* !_BUFFER_H_ */