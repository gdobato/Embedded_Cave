#ifndef __BLE_HCI_H__
#define __BLE_HCI_H__

#include <cstdint>
#include <ble_hci_base.h>



namespace bsp::ble
{

class HCI: public HCI_Base
{
  public:
  HCI() = default;
  void init (void); 
  ~HCI() = default;


};

}

#endif