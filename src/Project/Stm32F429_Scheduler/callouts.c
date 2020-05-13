

void Interrupts_Enable   (void) { __asm("cpsie i");}
void Interrupts_Disable  (void) { __asm("cpsid i");}