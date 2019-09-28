#ifndef __STM32F407_REG_H__
#define __STM32F407_REG_H__


#define PERIPHERAL_BASE (0x40000000UL)



/* RCC */
#define RCC_BASE         (PERIPHERAL_BASE + 0x00023800UL)
#define RCC_CR_ADR       (RCC_BASE + 0x00UL)
#define RCC_PLLCFGR_ADR  (RCC_BASE + 0x04UL)
#define RCC_CFGR_ADR     (RCC_BASE + 0x08UL)
#define RCC_CIR_ADR      (RCC_BASE + 0x0CUL)
#define RCC_AHB1ENR_ADR  (RCC_BASE + 0x30UL)  
#define RCC_AHB1ENR      (*((volatile unsigned int *)(RCC_AHB1ENR_ADR)))

/* FLASH */
#define FLASH_BASE (PERIPHERAL_BASE + 0x00023C00UL)
#define FLASH_ACR_ADR  (FLASH_BASE + 0x00UL)
#define FLASH_ACR      (*((volatile unsigned int *)(FLASH_ACR_ADR)))

/* FPU */
#define CPACR_ADR 0xE000ED88
#define CPACR     (*(volatile unsigned long*)(CPACR_ADR))



#endif
