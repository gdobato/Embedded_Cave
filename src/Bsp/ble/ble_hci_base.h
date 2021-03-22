#ifndef __BLE_HCI_BASE_H__
#define __BLE_HCI_BASE_H__

#include <cstdint>

namespace bsp::ble
{

class HCI_Base
{
  public:
    HCI_Base()=default;
    void init () {};
    virtual ~HCI_Base() = default;
};


}


#endif