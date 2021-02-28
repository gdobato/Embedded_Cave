#ifndef __BLE_SERVER_BASE_H__
#define __BLE_SERVER_BASE_H__

#include <string>
#include <iostream>
#include <functional>
#include <cstdint>
#include <ble_gap.h>
#include <ble_gatt.h>
#include <ble_hci.h>

namespace app::ble
{

class Server_Base
{
  public:
    Server_Base(GATT& gatt, GAP& gap, bsp::ble::HCI& hci):gatt(gatt),gap(gap), hci(hci){};
    virtual ~Server_Base() = default;

    virtual void init(void)    = 0;
    virtual void process(void) = 0;
  

  private:
    GATT&  gatt;
    GAP&   gap;
    bsp::ble::HCI&   hci;

};


}
#endif //__BLE_SERVER_H__
