#ifndef __BLE_GAP_H__
#define __BLE_GAP_H__

#include <cstdint>
#include <ble_gap_base.h>


namespace app::ble
{

class GAP : public GAP_Base
{
  public:
    GAP() = default;
    GAP(const GAP& gatt) = delete;
    virtual void init(uint8_t, uint8_t, uint8_t, uint16_t*){};
    virtual ~GAP() = default;
};

}
#endif