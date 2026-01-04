// timer.c
#include "timer.h"
#include "FreeRTOS.h"
#include "task.h"

// Define the frequency for the SysTick interrupt
#define SYS_TICK_FREQUENCY    1000  // 1ms interrupt frequency

// Function to initialize SysTick Timer
void SysTick_Init(uint32_t frequency) {
    // Configure SysTick for a periodic interrupt
    SysTick_Config(frequency);
}

// SysTick interrupt handler (called every 1ms)
void SysTick_Handler(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // Trigger context switch on each SysTick interrupt
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
