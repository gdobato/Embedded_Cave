#include <cstdint>
#include <ble_hci_base.h>
#include <ble_hci.h>
#include <hal.h>
#include "hci_const.h"
#include "hci.h"
#include "hci_le.h"




//void bsp::ble::HCI::init(void)
namespace bsp::ble {
void HCI_init(void)
{
  hci_init(NULL,NULL);
  hci_reset();
  HAL_Delay(100);
}
}

