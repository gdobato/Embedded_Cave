#ifndef __BLE_GATT_H__
#define __BLE_GATT_H__

#include <cstdint>
#include <ble_gatt_base.h>

namespace app::ble 
{

class GATT : public GATT_Base
{
  public:
    GATT() = default;
    GATT(const GATT& gatt) = delete;
    virtual void init(uint8_t, uint8_t, uint8_t, uint16_t*){}; 
    virtual ~GATT() = default;
};

}

#endif