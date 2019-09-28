/**
  ******************************************************************************
  * @file    stm32f4xx_BareMetal_spi.h
  * @author  Jenifer Blanco
  * @brief   Header file of SPI module.
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32F4xx_BAREMETAL_SPI_H
#define STM32F4xx_BAREMETAL_SPI_H

#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f4xx_BareMetal.h"


/* Configuration structure for SPIx peirpheral */
typedef struct 
{
  uint32_t Mode;                /*!< Specifies the SPI operating mode.
                                     This parameter can be a value of @ref SPI_Mode */

  uint32_t Direction;           /*!< Specifies the SPI bidirectional mode state.
                                     This parameter can be a value of @ref SPI_Direction */

  uint32_t DataSize;            /*!< Specifies the SPI data size.
                                     This parameter can be a value of @ref SPI_Data_Size */

  uint32_t CLKPolarity;         /*!< Specifies the serial clock steady state.
                                     This parameter can be a value of @ref SPI_Clock_Polarity */

  uint32_t CLKPhase;            /*!< Specifies the clock active edge for the bit capture.
                                     This parameter can be a value of @ref SPI_Clock_Phase */

  uint32_t NSS;                 /*!< Specifies whether the NSS signal is managed by
                                     hardware (NSS pin) or by software using the SSI bit.
                                     This parameter can be a value of @ref SPI_Slave_Select_management */

  uint32_t BaudRatePrescaler;   /*!< Specifies the Baud Rate prescaler value which will be
                                     used to configure the transmit and receive SCK clock.
                                     This parameter can be a value of @ref SPI_BaudRate_Prescaler
                                     @note The communication clock is derived from the master
                                     clock. The slave clock does not need to be set. */

  uint32_t FirstBit;            /*!< Specifies whether data transfers start from MSB or LSB bit.
                                     This parameter can be a value of @ref SPI_MSB_LSB_transmission */

  uint32_t TIMode;              /*!< Specifies if the TI mode is enabled or not.
                                     This parameter can be a value of @ref SPI_TI_mode */

  uint32_t CRCCalculation;      /*!< Specifies if the CRC calculation is enabled or not.
                                     This parameter can be a value of @ref SPI_CRC_Calculation */

  uint32_t CRCPolynomial;       /*!< Specifies the polynomial used for the CRC calculation.
                                     This parameter must be an odd number between Min_Data = 1 and Max_Data = 65535 */
}SPI_Config_t;

/*Handle structure for SPIx peripheral */
typedef struct
{
  SPI_Reg_t *pSPIx;
  SPI_Config_t SPIConfig;
}SPI_Handle_t;

/*@SPI_SCLKSpeed*/
#define SPI_SCLK_SPEED_DIV2   0 
#define SPI_SCLK_SPEED_DIV4   1 
#define SPI_SCLK_SPEED_DIV8   2 
#define SPI_SCLK_SPEED_DIV16  3 
#define SPI_SCLK_SPEED_DIV32  4 
#define SPI_SCLK_SPEED_DIV64  5 
#define SPI_SCLK_SPEED_DIV128 6 
#define SPI_SCLK_SPEED_DIV256 7 

/*@SPI_DeviceMode*/
#define SPI_DEVICE_MODE_MASTER 1
#define SPI_DEVICE_MODE_SLAVE  0

/*@SPI_Direction*/
#define SPI_BUS_CONFIG_FD 1
#define SPI_BUS_CONFIG_HD  0
#define SPI_BUS_CONFIG_SIMPLEX_RXONLY 2

/*@SPI_DataSize*/
#define SPI_DFF_8BITS 0
#define SPI_DFF_16BITS 1

/*@SPI_CLKPolarity*/
#define SPI_CPOL_HIGH 1
#define SPI_CPOL_LOW 0

/*@SPI_CLKPhase*/
#define SPI_CPHA_HIGH 1
#define SPI_CPHA_LOW 0

/*@SPI_NSS*/
#define SPI_SSM_EN 1
#define SPI_SSM_DI 0

/*@SPI_FirstBit*/
/*@SPI_TIMode*/
/*@SPI_CRCCalculation*/
/*@SPI_CRCPolynomial*/

/*SPI related status flags definitions*/
#define SPI_TXE_FLAG (1<<SPI_SR_TXE)
#define SPI_RXNE_FLAG (1<<SPI_SR_RXNE)
#define SPI_BUSY_FLAG (1<<SPI_SR_BSY)

/*******************************************************************************************
 *                              APIs supported by this driver
 *      For more information about the APIs check the funciton definitions
 * *****************************************************************************************/
/*Peripheral Clock Setup */
void SPI_PeripheralClockControl(SPI_Reg_t *pSPIx,uint8_t EnorDi);

/*Init and De-Init */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_Reg_t *pSPIx);

/*Data Send and Receive Blocking Type */
void SPI_SendData(SPI_Reg_t *pSPIx,uint8_t *pTxBuffer,uint32_t Len);
void SPI_ReceiveData(SPI_Reg_t *pSPIx,uint8_t *pRxBuffer,uint32_t Len);

/*Data Send and Receive Non-Blocking Type */

/*Data Send and Receive DMA Type */

/* IRQ Configuration and ISR Handling */
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi);
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority);
void SPI_IRQHandling(SPI_Handle_t *pHandle);

uint8_t SPI_GetFlagStatus(SPI_Reg_t *pSPIx, uint32_t FlagName);





#ifdef __cplusplus
}
#endif

#endif /* STM32F4xx_BAREMETAL_SPI_H */

/************************ END OF FILE********************************************/