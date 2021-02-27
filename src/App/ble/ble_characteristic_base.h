#ifndef __BLE_CHARACTERISTIC_BASE_H__
#define __BLE_CHARACTERISTIC_BASE_H__
#include <cstdint>
#include <string>
#include <array>

namespace app::ble
{

class Characteristic_Base
{
  public:
    using properties_t = enum {
                              broadcast              = 0x01,
                              read                   = 0x02,
                              write_without_response = 0x04,
                              write                  = 0x08,
                              notify                 = 0x10,
                              indicate               = 0x20,
                              signed_write_command   = 0x40,
                              queued_write           = 0x80,
                             };
    Characteristic_Base(const char* uuid, properties_t properties, uint16_t handle);
    virtual ~Characteristic_Base()=default;
  private:
  
};

}

#endif