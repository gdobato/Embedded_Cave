#include <common/TouchGFXInit.hpp>
#include <touchgfx/hal/BoardConfiguration.hpp>
#include <touchgfx/hal/GPIO.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>

#include <STM32F4HAL.hpp>
#include <STM32F4DMA.hpp>

#include <STM32F4Instrumentation.hpp>
#include <STM32F4TouchController.hpp>

/* USER CODE BEGIN user includes */

/* USER CODE END user includes */

/***********************************************************
 ******   Single buffer in internal RAM              *******
 ***********************************************************
 * On this platform, TouchGFX is able to run using a single
 * frame buffer in internal SRAM, thereby avoiding the need
 * for external SDRAM.
 * This feature was introduced in TouchGFX 4.7.0. To enable it,
 * uncomment the define below. The function touchgfx_init()
 * later in this file will check for this define and configure
 * TouchGFX accordingly.
 * For details on the single buffer strategy, please refer to
 * the knowledge base article "Single vs double buffering in TouchGFX"
 * on our support site.
 */
//#define SINGLE_FRAME_BUFFER_INTERNAL

/***********************************************************
 ******         24 Bits Per Pixel Support            *******
 ***********************************************************
 *
 * The default bit depth of the framebuffer is 16bpp. If you want 24bpp support, define the symbol "USE_BPP" with a value
 * of "24", e.g. "USE_BPP=24". This symbol affects the following:
 *
 * 1. Type of TouchGFX LCD (16bpp vs 24bpp)
 * 2. Bit depth of the framebuffer(s)
 * 3. TFT controller configuration.
 *
 * WARNING: Remember to modify your image formats accordingly in app/config/. Please see the following knowledgebase article
 * for further details on how to choose and configure the appropriate image formats for your application:
 *
 * https://touchgfx.zendesk.com/hc/en-us/articles/206725849
 */

 #include "HW_Init.hpp"

extern "C"
{

#include "stm32f4xx.h"
#include "stm32f4xx_hal_dma.h"
#include "stm32f4xx_hal_rcc_ex.h"
#include "stm32f4xx_hal_tim.h"

}

static uint32_t frameBuf0 = (uint32_t)(0xd0000000);
extern "C" {

extern void MX_SPI5_Init(void);
extern SPI_HandleTypeDef  hspi5;

extern void MX_SPI5_Init(void);
extern SPI_HandleTypeDef  hspi5;

/* In case of use of STM32429-DISCO board */

/* Chip Select macro definition */
#define LCD_CS_LOW()       HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_RESET)
#define LCD_CS_HIGH()      HAL_GPIO_WritePin(GPIOC, GPIO_PIN_2, GPIO_PIN_SET)

/* Set WRX High to send data */
#define LCD_WRX_LOW()       HAL_GPIO_WritePin(GPIOD,  GPIO_PIN_13, GPIO_PIN_RESET)
#define LCD_WRX_HIGH()      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_13, GPIO_PIN_SET)

/* Set RDX High to send data */
#define LCD_RDX_LOW()       HAL_GPIO_WritePin(GPIOD,  GPIO_PIN_12, GPIO_PIN_RESET)
#define LCD_RDX_HIGH()      HAL_GPIO_WritePin(GPIOD, GPIO_PIN_12, GPIO_PIN_SET)

/**
  * @brief  SPIx error treatment function.
  */
static void SPIx_Error(void)
{
  /* De-initialize the SPI communication BUS */
  HAL_SPI_DeInit(&hspi5);
  
  /* Re- Initialize the SPI communication BUS */
   MX_SPI5_Init();
}

/**
  * @brief  Reads 4 bytes from device.
  * @param  ReadSize: Number of bytes to read (max 4 bytes)
  * @retval Value read on the SPI
  */
static uint32_t SPIx_Read(uint8_t ReadSize)
{
  HAL_StatusTypeDef status = HAL_OK;
  uint32_t readvalue;
  
  status = HAL_SPI_Receive(&hspi5, (uint8_t*) &readvalue, ReadSize, 0x1000);
  
  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initialize the BUS */
    SPIx_Error();
  }
  
  return readvalue;
}

/**
  * @brief  Writes a byte to device.
  * @param  Value: value to be written
  */
static void SPIx_Write(uint16_t Value)
{
  HAL_StatusTypeDef status = HAL_OK;
  
  status = HAL_SPI_Transmit(&hspi5, (uint8_t*) &Value, 1, 0x1000);
  
  /* Check the communication status */
  if(status != HAL_OK)
  {
    /* Re-Initialize the BUS */
    SPIx_Error();
  }
}

/**
  * @brief  Configures the LCD_SPI interface.
  */
__weak void LCD_IO_Init(void)
{
   /* Set or Reset the control line */
    LCD_CS_LOW();
    LCD_CS_HIGH();
    MX_SPI5_Init();
}

/**
  * @brief  Writes register address.
  */
__weak void LCD_IO_WriteReg(uint8_t Reg) 
{
  /* Reset WRX to send command */
  LCD_WRX_LOW();
  
  /* Reset LCD control line(/CS) and Send command */
  LCD_CS_LOW();
  SPIx_Write(Reg);
  
  /* Deselect: Chip Select high */
  LCD_CS_HIGH();
}
/**
  * @brief  Writes register value.
  */

__weak void LCD_IO_WriteData(uint16_t RegValue) 
{
  /* Set WRX to send data */
  LCD_WRX_HIGH();
  
  /* Reset LCD control line(/CS) and Send data */  
  LCD_CS_LOW();
  SPIx_Write(RegValue);
  
  /* Deselect: Chip Select high */
  LCD_CS_HIGH();
}

/**
  * @brief  Reads register value.
  * @param  RegValue Address of the register to read
  * @param  ReadSize Number of bytes to read
  * @retval Content of the register value
  */

__weak uint32_t LCD_IO_ReadData(uint16_t RegValue, uint8_t ReadSize) 
{
  uint32_t readvalue = 0;

  /* Select: Chip Select low */
  LCD_CS_LOW();

  /* Reset WRX to send command */
  LCD_WRX_LOW();
  
  SPIx_Write(RegValue);
  
  readvalue = SPIx_Read(ReadSize);

  /* Set WRX to send data */
  LCD_WRX_HIGH();

  /* Deselect: Chip Select high */
  LCD_CS_HIGH();
  
  return readvalue;
}

/**
  * @brief  Wait for loop in ms.
  * @param  Delay in ms.
  */
void LCD_Delay(uint32_t Delay)
{
  HAL_Delay(Delay);
}

uint32_t LCD_GetXSize(void)
{
  return 240;
}

uint32_t LCD_GetYSize(void)
{
  return 320;
}
}

void GRAPHICS_HW_Init()
{
    

    /* Initialize the SDRAM */
    MX_FMC_Init();
    MX_SDRAM_InitEx();

    /* Configure LCD */
    MX_LCD_Init();
    GPIO::init();

}

STM32F4DMA dma;
STM32F4TouchController tc;
STM32F4Instrumentation mcuInstr;

static LCD16bpp display;
static uint16_t bitdepth = 16;

namespace touchgfx
{
void touchgfx_init()
{
  uint16_t dispWidth = 240;
  uint16_t dispHeight = 320;  
  
  HAL& hal = touchgfx_generic_init<STM32F4HAL>(dma, display, tc, dispWidth, dispHeight,(uint16_t*) 0, 
                                               0, 0); 

    hal.setFrameBufferStartAddress((uint16_t*)frameBuf0, bitdepth ,true , true);

    hal.setTouchSampleRate(2);
    hal.setFingerSize(1);

    // By default frame rate compensation is off.
    // Enable frame rate compensation to smooth out animations in case there is periodic slow frame rates.
    hal.setFrameRateCompensation(false);

    // This platform can handle simultaneous DMA and TFT accesses to SDRAM, so disable lock to increase performance.
    hal.lockDMAToFrontPorch(false);

    mcuInstr.init();

    //Set MCU instrumentation and Load calculation
    hal.setMCUInstrumentation(&mcuInstr);
    hal.enableMCULoadCalculation(true);
}
}

void GRAPHICS_Init()
{
   touchgfx::touchgfx_init();
}

void GRAPHICS_MainTask(void)
{
    touchgfx::HAL::getInstance()->taskEntry();
}
