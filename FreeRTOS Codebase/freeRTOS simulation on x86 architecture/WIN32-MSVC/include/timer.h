#ifndef TIMER_H
#define TIMER_H

void SysTick_Init(uint32_t frequency);
void SysTick_Handler(void);  // SysTick interrupt handler

#endif
