/**
 * @file  CPP Wrapper of generated files
 * @author 
 * @date
 * @brief
 **/

#include <hal.h>

static TIM_HandleTypeDef htim1;
static TIM_HandleTypeDef htim6;

static void ErrorHandler();

namespace bsp::timer
{
  void Init(void)
  {

    TIM_ClockConfigTypeDef sClockSourceConfig = {0};
    TIM_MasterConfigTypeDef sMasterConfig = {0};

    htim1.Instance = TIM1;
    htim1.Init.Prescaler = 0;
    htim1.Init.CounterMode = TIM_COUNTERMODE_UP;
    htim1.Init.Period = 0;
    htim1.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
    htim1.Init.RepetitionCounter = 0;
    htim1.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
    if (HAL_TIM_Base_Init(&htim1) != HAL_OK)
    {
      ErrorHandler();
    }
    sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
    if (HAL_TIM_ConfigClockSource(&htim1, &sClockSourceConfig) != HAL_OK)
    {
      ErrorHandler();
    }
    sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
    sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
    if (HAL_TIMEx_MasterConfigSynchronization(&htim1, &sMasterConfig) != HAL_OK)
    {
      ErrorHandler();
    }
  }
}

extern "C"
{
  HAL_StatusTypeDef HAL_InitTick(uint32_t TickPriority)
  {
    RCC_ClkInitTypeDef    clkconfig;
    uint32_t              uwTimclock = 0;
    uint32_t              uwPrescalerValue = 0;
    uint32_t              pFLatency;
    
    HAL_NVIC_SetPriority(TIM6_DAC_IRQn, TickPriority ,0); 
    HAL_NVIC_EnableIRQ(TIM6_DAC_IRQn); 
    __HAL_RCC_TIM6_CLK_ENABLE();
    HAL_RCC_GetClockConfig(&clkconfig, &pFLatency);
    uwTimclock = 2*HAL_RCC_GetPCLK1Freq();
    uwPrescalerValue = (uint32_t) ((uwTimclock / 1000000) - 1);
    htim6.Instance = TIM6;
    
    /* Initialize TIMx peripheral as follow:
    + Period = [(TIM6CLK/1000) - 1]. to have a (1/1000) s time base.
    + Prescaler = (uwTimclock/1000000 - 1) to have a 1MHz counter clock.
    + ClockDivision = 0
    + Counter direction = Up
    */
    htim6.Init.Period = (1000000 / 1000) - 1;
    htim6.Init.Prescaler = uwPrescalerValue;
    htim6.Init.ClockDivision = 0;
    htim6.Init.CounterMode = TIM_COUNTERMODE_UP;
    if(HAL_TIM_Base_Init(&htim6) == HAL_OK)
    {
      return HAL_TIM_Base_Start_IT(&htim6);
    }
    
    return HAL_ERROR;
  }

  void HAL_SuspendTick(void)
  {
    __HAL_TIM_DISABLE_IT(&htim6, TIM_IT_UPDATE);                                                  
  }

  void HAL_ResumeTick(void)
  {
    __HAL_TIM_ENABLE_IT(&htim6, TIM_IT_UPDATE);
  }

  void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
  {
    if (htim->Instance == TIM6) {
      HAL_IncTick();
    }
  }

  void TIM6_DAC_IRQHandler(void)
  {
    HAL_TIM_IRQHandler(&htim6);
  }

  uint32_t Get_Tick(void)
  {
    return HAL_GetTick();
  }

}

static void ErrorHandler()
{
  __asm("nop");
}