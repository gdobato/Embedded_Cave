#ifndef __BLE_SERVER_H__
#define __BLE_SERVER_H__

#include <string>
#include <iostream>
#include <functional>
#include <cstdint>
#include <ble_gap.h>
#include <ble_gatt.h>
#include <ble_hci.h>
#include <ble_server_base.h>

//tBleStatus aci_gap_init_IDB05A1(uint8_t role, uint8_t privacy_enabled, uint8_t device_name_char_len, uint16_t* service_handle, uint16_t* dev_name_char_handle, uint16_t* appearance_char_handle)
namespace app::ble
{

class Server : public Server_Base
{
  public:
  Server(GATT& gatt, GAP& gap, bsp::ble::HCI& hci):Server_Base(gatt,gap,hci){};
  void init (void) override;
  ~Server();


};


}
#endif //__BLE_SERVER_H__