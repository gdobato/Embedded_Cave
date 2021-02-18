
#include <stdint.h> 
extern "C" {
#include "bluenrg_gap.h"
#include "hci_const.h"
#include "bluenrg_hal_aci.h"
#include "hci.h"
#include "hci_le.h"
#include "bluenrg_gatt_aci.h"
#include "bluenrg_gap_aci.h"
#include "bluenrg_utils.h"
#include "ble_services.h"

void Ble_server_init(void)
{
	tBleStatus ret;
	
    const char* name = "test";
    const uint8_t server_addr[] = {0xA, 0xA, 0xA, 0xA, 0xA, 0xA};
	
	uint16_t service_handle, dev_name_char_handle, appearance_char_handle;
	
	hci_init(NULL,NULL);
	hci_reset();
	HAL_Delay(100);
	 
	aci_hal_write_config_data(CONFIG_DATA_PUBADDR_OFFSET,CONFIG_DATA_PUBADDR_LEN,(const uint8_t*)server_addr);
		
	aci_gatt_init();
	aci_gap_init_IDB05A1(GAP_PERIPHERAL_ROLE_IDB05A1,0,0x07,&service_handle,&dev_name_char_handle,&appearance_char_handle);
	aci_gatt_update_char_value(service_handle,dev_name_char_handle,0,strlen(name),(uint8_t *)name);
	
	
}

void Ble_server_process(void)
{
	tBleStatus ret;
    const char local_name[] = {AD_TYPE_COMPLETE_LOCAL_NAME,'B','L','E','-','T','E','S','T'};
	hci_le_set_scan_resp_data(0,NULL);
	
	aci_gap_set_discoverable(ADV_IND,0,0,PUBLIC_ADDR,NO_WHITE_LIST_USE,sizeof(local_name),local_name,0,NULL,0,0);
}  
}