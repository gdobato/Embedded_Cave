/**
  ******************************************************************************
  * @file    stm32f4xx_BareMetal_spi.c
  * @author  Jenifer Blanco
  * @brief   Source file of SPI Target module.
  ******************************************************************************
  */

#include "stm32f4xx_BareMetal_spi.h"
/*******************************************************************************
 * @fn      -SPI_PeripheralClockControl
 * 
 * @brief   -This function enables or disables peripheral clock for the given spi
 * 
 * @param[in] - base address of the spi peripheral
 * @param[in] - ENABLE or DISABLE macros
 * 
 * @return    - none
 * 
 * @note      - none
 * 
 ********************************************************************************/
void SPI_PeripheralClockControl(SPI_Reg_t *pSPIx,uint8_t EnorDi)
{
  if(EnorDi==ENABLE)
  {
    if(pSPIx==SPI5)
    {
      //SPI5_PCLK_EN();  @gabriel: commented out to remove compiler warning
    }

  }
  else
  {
    //TODO
  }
}

/*******************************************************************************
 * @fn      -SPI_Init
 * 
 * @brief   -This function enables or disables peripheral clock for the given spi
 * 
 * @param[in] - spi Handle
 * 
 * @return    - none
 * 
 * @note      - none
 * 
 ********************************************************************************/
void SPI_Init(SPI_Handle_t *pSPIHandle)
{
  //Configure SPI_CR1 Register
  uint32_t tempreg=0;
  // Configure device mode
  tempreg|=pSPIHandle->SPIConfig.Mode<<SPI_CR1_MSTR;
  //Configure Bus config
  if(pSPIHandle->SPIConfig.Direction==SPI_BUS_CONFIG_FD)
  {
    //bidi mode should be cleared
    tempreg &=~(1<<15);
  }else if(pSPIHandle->SPIConfig.Direction==SPI_BUS_CONFIG_HD)
  {
    //bidi mode should be set
     tempreg |=(1<<15);
  }else if (pSPIHandle->SPIConfig.Direction==SPI_BUS_CONFIG_SIMPLEX_RXONLY)
  {
    //bidi mode should be cleared 
    tempreg &=~(1<<SPI_CR1_BIDI_MODE);
    //rxonly bit must be set
    tempreg |=(1<<SPI_CR1_RX_ONLY);
  }
  //Configure the spi serial clock speed (baudrate)
  tempreg |=pSPIHandle->SPIConfig.BaudRatePrescaler << SPI_CR1_BR;

  //Configure the DFF
  tempreg |=pSPIHandle->SPIConfig.DataSize<<SPI_CR1_DFF; 

  //Configure the CPOL
  tempreg |=pSPIHandle->SPIConfig.CLKPolarity<<SPI_CR1_CPOL;

  //Configure the CPHA
  tempreg |=pSPIHandle->SPIConfig.CLKPhase<<SPI_CR1_CPHA;
  
  pSPIHandle->pSPIx->SPI_CR1=tempreg;
}
/*******************************************************************************
 * @fn      -SPI_DeInit
 * 
 * @brief   -This function enables or disables peripheral clock for the given spi
 * 
 * @param[in] - spi Handle
 * 
 * @return    - none
 * 
 * @note      - none
 * 
 ********************************************************************************/
void SPI_DeInit(SPI_Reg_t *pSPIx)
{
   if(pSPIx==SPI5)
    {
      SPI5_REG_RESET();
    }
}
/*******************************************************************************
 * @fn      -SPI_SendData
 * 
 * @brief   -This function send 8 or 16 bytes of data
 * 
 * @param[in] - SPI_Reg_t
 * @param[in] - pTxBuffer
 * @param[in] - Len
 * 
 * @return    - none
 * 
 * @note      - This is bloking call
 * 
 ********************************************************************************/
void SPI_SendData(SPI_Reg_t *pSPIx,uint8_t *pTxBuffer,uint32_t Len)
{
  while(Len>0)
  {
    //wait until TXE is set
    while(SPI_GetFlagStatus(pSPIx,SPI_TXE_FLAG)==FLAG_RESET);
    
    //check the DFF bit in CR1
    if(pSPIx->SPI_CR1 &(1<<SPI_CR1_DFF))
    {
      //16 bit DFF
      //load the data into the DR
      pSPIx->SPI_DR=*((uint16_t*)pTxBuffer);
      Len--;
      Len--;
      (uint16_t*)pTxBuffer++;
    }
    else
    {
      pSPIx->SPI_DR=*pTxBuffer;
      Len--;
      pTxBuffer++;
    }
  }
}
/*******************************************************************************
 * @fn      -SPI_GetFlagStatus
 * 
 * @brief   -This function return the value of the Flag
 * 
 * @param[in] - SPI_Reg_t
 * @param[in] - SPI_Reg_t
 * 
 * @return    - none
 * 
 * @note      - none
 * 
 ********************************************************************************/
uint8_t SPI_GetFlagStatus(SPI_Reg_t *pSPIx, uint32_t FlagName)
{
  if(pSPIx->SPI_SR & FlagName)
  {
    return FLAG_SET;
  }
 return FLAG_RESET;
}
/*******************************************************************************
 * @fn      -SPI_ReceiveData
 * 
 * @brief   -This function enables or disables peripheral clock for the given spi
 * 
 * @param[in] - spi Handle
 * 
 * @return    - none
 * 
 * @note      - none
 * 
 ********************************************************************************/
void SPI_ReceiveData(SPI_Reg_t *pSPIx,uint8_t *pRxBuffer,uint32_t Len)
{

  
}
/*******************************************************************************
 * @fn      -SPI_IRQInterruptConfig
 * 
 * @brief   -This function enables or disables peripheral clock for the given spi
 * 
 * @param[in] - spi Handle
 * 
 * @return    - none
 * 
 * @note      - none
 * 
 ********************************************************************************/
void SPI_IRQInterruptConfig(uint8_t IRQNumber, uint8_t EnorDi)
{

}
/*******************************************************************************
 * @fn      -SPI_IRQPriorityConfig
 * 
 * @brief   -This function enables or disables peripheral clock for the given spi
 * 
 * @param[in] - spi Handle
 * 
 * @return    - none
 * 
 * @note      - none
 * 
 ********************************************************************************/
void SPI_IRQPriorityConfig(uint8_t IRQNumber, uint32_t IRQPriority)
{

}/*******************************************************************************
 * @fn      -SPI_IRQHandling
 * 
 * @brief   -This function enables or disables peripheral clock for the given spi
 * 
 * @param[in] - spi Handle
 * 
 * @return    - none
 * 
 * @note      - none
 * 
 ********************************************************************************/

void SPI_IRQHandling(SPI_Handle_t *pHandle)
{


}
