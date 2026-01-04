#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>  // Required for uint32_t and other fixed-width types

// Simulated SysTick Interrupt Handler for FreeRTOS tick
void SysTick_Handler(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // Trigger a context switch after each SysTick interrupt (handled by Windows timer)
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

// Simulated UART Interrupt Handler for data reception
void UART_IRQHandler(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    
    // Simulate UART data reception by manually inputting or polling data
    // Placeholder: Simulate receiving a character
    char received_char = 'A';  // Simulate received character (this could be from input)

    // Handle the received character (e.g., store in buffer)
    uart_receive_char(received_char);  // Process the received character

    // Trigger a context switch if required
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
