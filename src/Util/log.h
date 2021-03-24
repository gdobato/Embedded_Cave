#ifndef __LOG_H__

#include <usart.h>
#include <timer.h>
#include <string>
#include <string.h> //ToDo:Remove when ETL integrated
namespace util::log 
{
  using namespace bsp::timer;
  class Serial final
  {
    public:
      using interface_type = bsp::usart::Usart;

      Serial() = delete;
      Serial(const interface_type& interface):interface(interface){};
     ~Serial() = default;

      template<typename...Args>
      void print(const char* format, Args...args)
      {
        interface.transmit(reinterpret_cast<const uint8_t*>(format), strlen(format));
        //Use initializer list insteadd  of recursion
        std::initializer_list<int>{(print(args), 0)...};
      }

      template<typename...Args>
      void print_ts(const char* format, Args...args)
      {
        auto tick = std::to_string(Get_Tick());
        //Use ETL when integrated
        std::string ts{tick};
        ts.append("ms: ");
        interface.transmit(reinterpret_cast<const uint8_t*>(ts.c_str()), ts.length());
        print(format,args...);
      }

      void print(char* format)
      {
        interface.transmit(reinterpret_cast<const uint8_t*>(format), strlen(format));
      }

      template<typename T>
      void print(T t1)
      {
        //Use ETL when integrated
        auto s = std::to_string(t1);
        interface.transmit(reinterpret_cast<const uint8_t*>(s.c_str()), s.length());
      }


    private:

      interface_type interface; 
  };
}

#endif