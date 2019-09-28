#ifndef __GPIO_H__
#define __GPIO_H__


//===============================================================================================================================
// Defines
//===============================================================================================================================
#define GPIOA_BASE 0x40020000UL
#define GPIOB_BASE 0x40020400UL
#define GPIOC_BASE 0x40020800UL
#define GPIOD_BASE 0x40020C00UL
#define GPIOE_BASE 0x40021000UL

#define GPIOD_MODER   (GPIOD_BASE + 0x00UL)
#define GPIOD_OSPEEDR (GPIOD_BASE + 0x08UL)
#define GPIOD_ODR     (GPIOD_BASE + 0x14UL)

#define GPIOC_MODER   (GPIOC_BASE + 0x00UL)
#define GPIOC_OSPEEDR (GPIOC_BASE + 0x08UL)
#define GPIOC_ODR     (GPIOC_BASE + 0x14UL)

//===============================================================================================================================
// Type definitions
//===============================================================================================================================

typedef struct
{
  unsigned int MODER0 :2;
  unsigned int MODER1 :2;
  unsigned int MODER2 :2;
  unsigned int MODER3 :2;
  unsigned int MODER4 :2;
  unsigned int MODER5 :2;
  unsigned int MODER6 :2;
  unsigned int MODER7 :2;
  unsigned int MODER8 :2;
  unsigned int MODER9 :2;
  unsigned int MODER10:2;
  unsigned int MODER11:2;
  unsigned int MODER12:2;
  unsigned int MODER13:2;
  unsigned int MODER14:2;
  unsigned int MODER15:2;
}GPIOx_MODER_bit;

typedef struct
{
  unsigned int ODR0 :1;
  unsigned int ODR1 :1;
  unsigned int ODR2 :1;
  unsigned int ODR3 :1;
  unsigned int ODR4 :1;
  unsigned int ODR5 :1;
  unsigned int ODR6 :1;
  unsigned int ODR7 :1;
  unsigned int ODR8 :1;
  unsigned int ODR9 :1;
  unsigned int ODR10:1;
  unsigned int ODR11:1;
  unsigned int ODR12:1;
  unsigned int ODR13:1;
  unsigned int ODR14:1;
  unsigned int ODR15:1;
  unsigned int :15;
}GPIOx_ODR_bit;

typedef struct
{
  unsigned int OSPEEDR0 :2;
  unsigned int OSPEEDR1 :2;
  unsigned int OSPEEDR2 :2;
  unsigned int OSPEEDR3 :2;
  unsigned int OSPEEDR4 :2;
  unsigned int OSPEEDR5 :2;
  unsigned int OSPEEDR6 :2;
  unsigned int OSPEEDR7 :2;
  unsigned int OSPEEDR8 :2;
  unsigned int OSPEEDR9 :2;
  unsigned int OSPEEDR10:2;
  unsigned int OSPEEDR11:2;
  unsigned int OSPEEDR12:2;
  unsigned int OSPEEDR13:2;
  unsigned int OSPEEDR14:2;
  unsigned int OSPEEDR15:2;
}GPIOx_OSPEEDR_bit;

#define GPIO_INPUT  0
#define GPIO_OUTPUT 1

#define GPIO_SPEED  0

//===============================================================================================================================
// ROM Globals
//===============================================================================================================================
static volatile GPIOx_MODER_bit*   const pGPIOD_MODER   = (volatile GPIOx_MODER_bit* const)GPIOD_MODER;
static volatile GPIOx_ODR_bit*     const pGPIOD_ODR     = (volatile GPIOx_ODR_bit* const)GPIOD_ODR;
static volatile GPIOx_OSPEEDR_bit* const pGPIOD_OSPEEDR = (volatile GPIOx_OSPEEDR_bit* const)GPIOD_OSPEEDR;

static volatile GPIOx_MODER_bit*   const pGPIOC_MODER   = (volatile GPIOx_MODER_bit* const)GPIOC_MODER;
static volatile GPIOx_ODR_bit*     const pGPIOC_ODR     = (volatile GPIOx_ODR_bit* const)GPIOC_ODR;
static volatile GPIOx_OSPEEDR_bit* const pGPIOC_OSPEEDR = (volatile GPIOx_OSPEEDR_bit* const)GPIOC_OSPEEDR;


//===============================================================================================================================
// LEDs Macros
//===============================================================================================================================
#define LED_GREEN_ON()      pGPIOD_OSPEEDR->OSPEEDR12 = GPIO_SPEED; pGPIOD_MODER->MODER12 = GPIO_OUTPUT; pGPIOD_ODR->ODR12 = 1
#define LED_GREEN_OFF()     pGPIOD_OSPEEDR->OSPEEDR12 = GPIO_SPEED; pGPIOD_MODER->MODER12 = GPIO_OUTPUT; pGPIOD_ODR->ODR12 = 0
#define LED_GREEN_TOGGLE()  pGPIOD_OSPEEDR->OSPEEDR12 = GPIO_SPEED; pGPIOD_MODER->MODER12 = GPIO_OUTPUT; pGPIOD_ODR->ODR12 ^= 1

#define LED_ORANGE_ON()      pGPIOD_OSPEEDR->OSPEEDR13 = GPIO_SPEED; pGPIOD_MODER->MODER13 = GPIO_OUTPUT; pGPIOD_ODR->ODR13 = 1
#define LED_ORANGE_OFF()     pGPIOD_OSPEEDR->OSPEEDR13 = GPIO_SPEED; pGPIOD_MODER->MODER13 = GPIO_OUTPUT; pGPIOD_ODR->ODR13 = 0
#define LED_ORANGE_TOGGLE()  pGPIOD_OSPEEDR->OSPEEDR13 = GPIO_SPEED; pGPIOD_MODER->MODER13 = GPIO_OUTPUT; pGPIOD_ODR->ODR13 ^= 1


#define LED_RED_ON()      pGPIOD_OSPEEDR->OSPEEDR14 = GPIO_SPEED; pGPIOD_MODER->MODER14 = GPIO_OUTPUT; pGPIOD_ODR->ODR14 = 1
#define LED_RED_OFF()     pGPIOD_OSPEEDR->OSPEEDR14 = GPIO_SPEED; pGPIOD_MODER->MODER14 = GPIO_OUTPUT; pGPIOD_ODR->ODR14 = 0
#define LED_RED_TOGGLE()  pGPIOD_OSPEEDR->OSPEEDR14 = GPIO_SPEED; pGPIOD_MODER->MODER14 = GPIO_OUTPUT; pGPIOD_ODR->ODR14 ^= 1


#define LED_BLUE_ON()      pGPIOD_OSPEEDR->OSPEEDR15 = GPIO_SPEED; pGPIOD_MODER->MODER15 = GPIO_OUTPUT; pGPIOD_ODR->ODR15 = 1
#define LED_BLUE_OFF()     pGPIOD_OSPEEDR->OSPEEDR15 = GPIO_SPEED; pGPIOD_MODER->MODER15 = GPIO_OUTPUT; pGPIOD_ODR->ODR15 = 1
#define LED_BLUE_TOGGLE()  pGPIOD_OSPEEDR->OSPEEDR15 = GPIO_SPEED; pGPIOD_MODER->MODER15 = GPIO_OUTPUT; pGPIOD_ODR->ODR15 ^= 1

//===============================================================================================================================
// IO Macros
//===============================================================================================================================
#define PD9_TOGGLE()       pGPIOD_OSPEEDR->OSPEEDR9 = GPIO_SPEED; pGPIOD_MODER->MODER9 = GPIO_OUTPUT; pGPIOD_ODR->ODR9 ^= 1

#define PC9_MCO2_OUTPUT()  pGPIOC_MODER->MODER9 = 2; pGPIOC_OSPEEDR->OSPEEDR9 = 1;



#endif
