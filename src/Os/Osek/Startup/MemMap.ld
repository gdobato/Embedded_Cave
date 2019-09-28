
MEMORY
{
  ROM(rx)  : ORIGIN = 0x08000000, LENGTH = 1M
  RAM(rwx) : ORIGIN = 0x20000000, LENGTH = 192K
}

SECTIONS
{
  /* Interrupt vector table */
  .intvect :
  {
    *(.intvect)
    . = ALIGN(4);
    KEEP(*(.intvect))
  } > ROM

  /* Program code (text) */
  .text :
  {
    *(.text)
    . = ALIGN(4);
  } > ROM

  /* Read-only data (.rodata) */
  .rodata :
  {
    *(.rodata)
    . = ALIGN(4);
  } > ROM

  .romdata : {}   > ROM

  /* The ROM-to-RAM initialized data section */
  .data : AT (ADDR(.romdata))
  {
    *(.data)
    . = ALIGN(4);
  } > RAM

  /* The uninitialized (zero-cleared) data section */
  .bss :
  {
    *(.bss)
    . = ALIGN(4);
  } > RAM

  /* tbss section */
  .tbss :
  {
    *(.tbss)
    . = ALIGN(4);
  } > RAM

  /* stack definition */
  .stack :
  {
    . = ALIGN(MAX(1024 , .), 8);
  } > RAM


  _ROM_DATA_SECTION_BASE = LOADADDR(.data); 
  _ROM_DATA_SECTION_SIZE = SIZEOF(.data);
  _RAM_DATA_SECTION_BASE = ADDR(.data);
  _BSS_SECTION_BASE =  ADDR(.bss);
  _BSS_SECTION_SIZE = SIZEOF(.bss);
  _INITIAL_STACK_POINTER =  ADDR(.stack) + SIZEOF(.stack);
 
}
