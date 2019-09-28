
//=============================================================================
// Load region symbols (.data)
//=============================================================================
extern unsigned int _ROM_DATA_SECTION_BASE;
extern unsigned int _ROM_DATA_SECTION_SIZE;

#define ROM_DATA_SECTION_BASE (unsigned int)&_ROM_DATA_SECTION_BASE
#define ROM_DATA_SECTION_SIZE (unsigned int)&_ROM_DATA_SECTION_SIZE

//=============================================================================
// Execution region symbols (.data)
//=============================================================================
extern unsigned int _RAM_DATA_SECTION_BASE;

#define RAM_DATA_SECTION_BASE (unsigned int)&_RAM_DATA_SECTION_BASE

//=============================================================================
// Execution region symbols (.bss)
//=============================================================================
extern unsigned int _BSS_SECTION_BASE;
extern unsigned int _BSS_SECTION_SIZE;
#define BSS_SECTION_BASE (unsigned int)&_BSS_SECTION_BASE
#define BSS_SECTION_SIZE (unsigned int)&_BSS_SECTION_SIZE


//=============================================================================
// function prototype
//=============================================================================
void SysStartup_Init(void);
static void SysStartup_InitRam(void);
static void SysStartup_Memset(unsigned char* ptr,int value, unsigned int size);
static void SysStartup_Memcpy(unsigned char* target, const unsigned char* source, unsigned int size);
static void SysStartup_RunApplication(void);
static void SysStartup_Unexpected_Exit(void);
static void SysStartup_InitCore(void);

//=============================================================================
// extern function prototype
//=============================================================================
int main(void)__attribute__((weak));
void STM32F407_InitCpu(void)__attribute__((weak));  


//-----------------------------------------------------------------------------
/// \brief  Memset function
///
/// \param  unsigned char* ptr: pointer to the target memory
///                 int value : initliaziation value 
///         unsigned int size : size of the memory region to set
///
/// \return void
//-----------------------------------------------------------------------------
static void SysStartup_Memset(unsigned char* ptr,int value, unsigned int size)
{
  while(size--)
  {
    *((unsigned char*)(ptr++)) = value;
  }
}
//-----------------------------------------------------------------------------
/// \brief  Memcpy function
///
/// \param         unsigned char* target: pointer to the target memory region
///         const unsigned char* source : pointer to the source memory region
///                   unsigned int size : size of the memory region to copy
///
/// \return void
//-----------------------------------------------------------------------------
static void SysStartup_Memcpy(unsigned char* target, const unsigned char* source, unsigned int size)
{
  while(size--)
  {
    *((unsigned char*)(target++)) = *((const unsigned char*)(source++));
  }
}
//-----------------------------------------------------------------------------
/// \brief  SysStartup_Init function
///
/// \param  void
///
/// \return void
//-----------------------------------------------------------------------------
void SysStartup_Init(void)
{
  SysStartup_InitCore();        /* Configure the CPU */

  SysStartup_InitRam();         /* Init .bss and .data sections */

  SysStartup_RunApplication();  /* Call main function */	
}

//-----------------------------------------------------------------------------
/// \brief  SysStartup_InitRam function
///
/// \param  void
///
/// \return void
//-----------------------------------------------------------------------------
static void SysStartup_InitRam(void)
{
  /* Copie .data from ROM to RAM */
  if(ROM_DATA_SECTION_SIZE > 0)
  {
    SysStartup_Memcpy((unsigned char*)RAM_DATA_SECTION_BASE,(const unsigned char*)ROM_DATA_SECTION_BASE,ROM_DATA_SECTION_SIZE);
  }

  /* Init .bss section */
  if(BSS_SECTION_SIZE > 0)
  {
    SysStartup_Memset((unsigned char*)BSS_SECTION_BASE,0,BSS_SECTION_SIZE);
  }	
}

//-----------------------------------------------------------------------------
/// \brief  SysStartup_RunApplication function
///
/// \param  void
///
/// \return void
//-----------------------------------------------------------------------------
static void SysStartup_RunApplication(void)
{
  if((unsigned int) main != 0) /* check the weak function */
  {
    /* Call the main function */
    (void)main();            
  }

  SysStartup_Unexpected_Exit(); /* Catch unexpected exit from main or if main dosent exist */
}	

//-----------------------------------------------------------------------------
/// \brief  SysStartup_Unexpected_Exit function
///
/// \param  void
///
/// \return void
//-----------------------------------------------------------------------------
static void SysStartup_Unexpected_Exit(void)
{
  for(;;);	
}	
//-----------------------------------------------------------------------------
/// \brief  SysStartup_InitCore function
///
/// \param  void
///
/// \return void
//-----------------------------------------------------------------------------
static void SysStartup_InitCore(void)
{
  STM32F407_InitCpu();
}
