// interrupt_handlers.c
#include "FreeRTOS.h"
#include "task.h"

// SysTick Interrupt Handler for FreeRTOS tick
void SysTick_Handler(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // Trigger a context switch after each SysTick interrupt
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}

// UART Interrupt Handler for data reception
void UART_IRQHandler(void) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;
    
    // Read incoming data (placeholder)
    char received_char = UART_ReceiveChar(UART_BASE_ADDR);

    // Handle received character (e.g., store in buffer)
    uart_receive_char(received_char);

    // Trigger a context switch if required
    portYIELD_FROM_ISR(xHigherPriorityTaskWoken);
}
