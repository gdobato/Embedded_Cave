#ifndef __LOG_H__

//Place holder

namespace util::log 
{
  class Serial
  {
    template<typename... Args>
    void print(const char *s, Args... args);
  };

}

#endif