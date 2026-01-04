// device_drivers.c
#include "device_drivers.h"
#include "FreeRTOS.h"
#include "task.h"

void init_uart() {
    // Initialize UART for debugging/logging
    UART_Init(UART_BASE_ADDR);
    UART_SetBaudRate(UART_BASE_ADDR, UART_BAUD_RATE);
    UART_Enable(UART_BASE_ADDR);
}

void uart_send(char *message) {
    // Send a message through UART
    while (*message) {
        UART_SendChar(*message++);
    }
}

void init_timer() {
    // Initialize system timer to generate periodic interrupts (for context-switching)
    SysTick_Config(SYS_TICK_FREQUENCY);  // Set up SysTick interrupt for every 1ms
}
