
#define SYS_TICK_BASE_REG (0xE000E010UL)
	
#define STK_CTRL   *((volatile unsigned int*)(SYS_TICK_BASE_REG + 0x00))	
#define STK_LOAD   *((volatile unsigned int*)(SYS_TICK_BASE_REG + 0x04))	
#define STK_VAL    *((volatile unsigned int*)(SYS_TICK_BASE_REG + 0x08))	
#define STK_CALIB  *((volatile unsigned int*)(SYS_TICK_BASE_REG + 0x0C))
	
#define STK_CTRL_PTR  ((unsigned int*)(SYS_TICK_BASE_REG + 0x00))

typedef struct
{
  unsigned int Enable:1;
  unsigned int TickInt:1;
  unsigned int ClockSrc:1;
  unsigned int :13;
  unsigned int CountFlag:1;
  unsigned int :15;	
}stStkCtrl;

#define SYS_TICK_CLKSRC_AHB   1
#define SYS_TICK_ENABLE_INT   1
#define SYS_TICK_ENABLE_TIMER 1
#define SYS_TICK_1MS          (unsigned int)0x29040 - 1

volatile stStkCtrl* const StkCtrl = (stStkCtrl* const)STK_CTRL_PTR;


void SysTickTimer_Init(void)
{
  STK_CTRL          = 0;
  STK_LOAD          = SYS_TICK_1MS;
  STK_VAL           = 0;
  StkCtrl->ClockSrc = SYS_TICK_CLKSRC_AHB;
  StkCtrl->TickInt  = SYS_TICK_ENABLE_INT;	
}

void SysTickTimer_Start(void)
{
  StkCtrl->Enable = SYS_TICK_ENABLE_TIMER;
}