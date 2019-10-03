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
#include <led/ledThread.h> 
#include <debugThread.h> 

/************************************
* Private definitions 
************************************/

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/
static osThreadId DebugThread;
static osThreadId ledThread;

/************************************
* Private declarations 
************************************/

int main(void)
{
  HAL_Init();
  Gpio_Init();
  Usart_Init();

  /* definition and creation of debugTerminal */
  osThreadDef(Debug, DebugHandler, osPriorityNormal, 0, 512);
  DebugThread = osThreadCreate(osThread(Debug), NULL);
  
  /* definition and creation of Led thread */
  osThreadDef(Led, ledHandler, osPriorityNormal, 0, 512);
  ledThread = osThreadCreate(osThread(Led), NULL);

  osKernelStart();

  while (1)
  {
  }

  return 0;
}

