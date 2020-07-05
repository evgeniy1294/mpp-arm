#pragma once

namespace mpp::gpio
{
  class Interface
  {
    public:
      virtual void Write(bool state) = 0;
      virtual bool Read() = 0;
  };
}


