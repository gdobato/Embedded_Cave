//===============================================================================================================================
// includes
//===============================================================================================================================
#include "STM32F407_Reg.h"
#include "Gpio.h"

//===============================================================================================================================
// Types definitions
//===============================================================================================================================

/* RCC_PLLCFGR REGISTER */
typedef  struct
{
  unsigned int PLLM:6;
  unsigned int PLLN:9;
  unsigned int :1;
  unsigned int PLLP:2;
  unsigned int :4;
  unsigned int PLLSRC:1;
  unsigned int :1;
  unsigned int PLLQ:4;
  unsigned int :4;
}RCC_PLLCFGR_bit;

typedef union
{
  RCC_PLLCFGR_bit bit;
  unsigned int raw;
}RCC_PLLCFGR_Reg;


/* RCC_CR REGISTER */
typedef struct
{
  unsigned int HSION:1;
  unsigned int HSIRDY:1;
  unsigned int :1;
  unsigned int HSITRIM:5;
  unsigned int HSICAL:8;
  unsigned int HSEON:1;
  unsigned int HSERDY:1;
  unsigned int HSEBYP:1;
  unsigned int CSSON:1;
  unsigned int :4;
  unsigned int PLLON:1;
  unsigned int PLLRDY:1;
  unsigned int PLLI2SON:1;
  unsigned int PLLI2SRDY:1;
  unsigned int PLLSAION:1;
  unsigned int PLLSAIRDY:1;
  unsigned int :2;
}
RCC_CR_bit;

typedef union
{
  RCC_CR_bit bit;
  unsigned int raw;
}RCC_CR_Reg;


/* RCC_CFGR REGISTER */

typedef struct
{
  unsigned int SW:2;
  unsigned int SWS:2;
  unsigned int HPRE:4;
  unsigned int :2;
  unsigned int PPRE1:3;
  unsigned int PPRE2:3;
  unsigned int RTCPRE:5;
  unsigned int MCO1:2;
  unsigned int I2SSCR:1;
  unsigned int MCO1PRE:3;
  unsigned int MCO2PRE:3;
  unsigned int MCO2:2;
} 
RCC_CFGR_bit;

typedef union
{
  RCC_CFGR_bit bit;
  unsigned int raw;
}RCC_CFGR_Reg;

//===============================================================================================================================
// ROM Globals
//===============================================================================================================================
static volatile RCC_PLLCFGR_Reg* const pRCC_PLLCFGR = (RCC_PLLCFGR_Reg*)RCC_PLLCFGR_ADR;
static volatile RCC_CR_Reg* const pRCC_CR_Reg       = (RCC_CR_Reg*)RCC_CR_ADR;
static volatile RCC_CFGR_Reg* const pRCC_CFGR       = (RCC_CFGR_Reg*)RCC_CFGR_ADR;

//===============================================================================================================================
// Fucntions
//===============================================================================================================================
void STM32F407_InitClock(void)
{
  /* clear Cfgr */
  pRCC_CFGR->raw = 0;

  /* MCO2 source */
  pRCC_CFGR->bit.MCO2 = 3; //3: PLL Clock output

  /* MCO2 PRE*/
  pRCC_CFGR->bit.MCO2PRE = 6; //6: division by 4

  /* set AHB to 168MHz */
  pRCC_CFGR->bit.HPRE = 0;

  /* set APB1 to 42MHz */
  pRCC_CFGR->bit.PPRE1 = 5;

  /* set APB2 to 87MHz */
  pRCC_CFGR->bit.PPRE2 = 4;

  /* Enable HSE clock */
  pRCC_CR_Reg->bit.HSEBYP = 0;
  pRCC_CR_Reg->bit.HSEON  = 1;

  /* wait until HSE becomes ready */
  while(pRCC_CR_Reg->bit.HSERDY == 0);

  /* Enable the PLL */
  pRCC_CR_Reg->bit.PLLON = 0;
  
  /* wait until the PLL becomes ready */
  while(pRCC_CR_Reg->bit.PLLRDY == 1);

  /* set the PLL output to 168MHz */
  pRCC_PLLCFGR->bit.PLLSRC = 1;    //HSE source (8MHz)
  pRCC_PLLCFGR->bit.PLLM   = 4U;   //VCO input  (4MHz)
  pRCC_PLLCFGR->bit.PLLN   = 168U; //VCO output (336MHz)
  pRCC_PLLCFGR->bit.PLLP   = 0U;   //PLL output (168MHz)
  pRCC_PLLCFGR->bit.PLLQ   = 7U;   //PLL USB    (48MHz)

  /* Enable the PLL */
  pRCC_CR_Reg->bit.PLLON = 1;

  /* wait until the PLL becomes ready */
  while(pRCC_CR_Reg->bit.PLLRDY == 0);
  
  /* Set the PLL as system clock */
  pRCC_CFGR->bit.SW = 2;

  /* wait until the PLL becomes the system clock */
  while(pRCC_CFGR->bit.SWS != 2);

  /* Enable the clock for GPIO PORT D */
  RCC_AHB1ENR |= (1UL<<3U);

  /* Enable the clock for GPIO PORT C */
  RCC_AHB1ENR |= (1UL<<2U);

  /* Output the SysClock on MCO2 */
  PC9_MCO2_OUTPUT();
}
