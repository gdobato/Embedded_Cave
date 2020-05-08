/**
 * @file 
 * @author 
 * @date
 * @brief
 **/

/************************************
* Includes
************************************/
#include "stm32f4xx_hal.h"
#include "hal/hal.h"

/************************************
* Private type definitions 
************************************/

/************************************
* Private variables
************************************/
static CRC_HandleTypeDef hcrc;

/************************************
* Private declarations 
************************************/
static void Crc_ErrorHandler();

/************************************
* Implementation 
************************************/
/**
  * @brief CRC Initialization Function
  * @param None
  * @retval None
  */
void Crc_Init(void)
{

  /* USER CODE BEGIN CRC_Init 0 */

  /* USER CODE END CRC_Init 0 */

  /* USER CODE BEGIN CRC_Init 1 */

  /* USER CODE END CRC_Init 1 */
  hcrc.Instance = CRC;
  if (HAL_CRC_Init(&hcrc) != HAL_OK)
  {
    Crc_ErrorHandler();
  }
  /* USER CODE BEGIN CRC_Init 2 */

  /* USER CODE END CRC_Init 2 */

}

static void Crc_ErrorHandler(void)
{
  __asm("nop");
}