#ifndef __BLE_GATT_BASE_H__
#define __BLE_GATT_BASE_H__

#include <cstdint>

namespace app::ble
{

class GATT_Base
{
  public:
    GATT_Base() = default;
    GATT_Base(const GATT_Base& gatt) = delete;
    virtual void init(uint8_t, uint8_t, uint8_t, uint16_t*) = 0; 
    virtual ~GATT_Base() = default;
};

}

#endif