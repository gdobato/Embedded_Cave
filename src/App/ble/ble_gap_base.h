#ifndef __BLE_GAP_BASE_H__
#define __BLE_GAP_BASE_H__

#include <cstdint>
#include <string>
#include <array>

namespace app::ble
{

class GAP_Base
{
  public:
    GAP_Base(const std::string device_name) : device_name(device_name){};
    GAP_Base(const GAP_Base& gatt) = delete;
    virtual void init(uint8_t, uint8_t, uint8_t, uint16_t*) = 0; 
    virtual ~GAP_Base() = default;

  private:
    std::string            device_name;
    std::array<uint8_t, 6> static_addr;
    uint16_t               service_handle; 
    uint16_t               device_name_handle;
    uint16_t               appearance_char_handle;
};

}

#endif