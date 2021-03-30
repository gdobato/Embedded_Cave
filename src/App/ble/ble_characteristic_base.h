#ifndef __BLE_CHARACTERISTIC_BASE_H__
#define __BLE_CHARACTERISTIC_BASE_H__
#include <cstdint>
#include <string>
#include <array>

namespace app::ble
{
template<typename T>
class Characteristic
{
  public:
    Characteristic(const char* uuid, properties_t properties, uint16_t handle);
    virtual ~Characteristic()=default;
    void writeValue(T)
    
  private:
  
};

}

#endif