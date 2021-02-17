/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include <cmsis_os.h>
#include <system/system.h> 
#include <gpio/gpio.h> 
#include <usart/usart.h> 
#include <userLed/taskUserLed.h> 
#include <ble/ble_server_task.h>
#include <ble/ble_server.h>
#include <taskDebug.h> 
#include <timer/timer.h>

/************************************
* Private definitions 
************************************/

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/

/************************************
* Private declarations 
************************************/

int main(void)
{
  HAL_Init();
  Timer_Init();
  Gpio_Init();
  Usart_Init();
  ble_server_init();

  vTaskDebug_CreateQueue(3U);
  
  /* definition and creation of Led thread */
  xTaskCreate(vTaskLed         , "UserLed"   , 256  , NULL, 1, NULL );
  xTaskCreate(vTaskBleServer   , "bleserver" , 1024 , NULL, 2, NULL );
  xTaskCreate(vTaskDebug       , "Debug"     , 256  , NULL, 1, NULL );

  vTaskStartScheduler();


  while (1)
  {
  }

  return 0;
}

