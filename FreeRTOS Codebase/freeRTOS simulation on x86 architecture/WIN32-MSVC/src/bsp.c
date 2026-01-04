// bsp.c
#include "bsp.h"
#include "device_drivers.h"
#include "interrupt_handlers.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>  // Required for uint32_t and other fixed-width types

// Define necessary hardware registers and constants for MIPS32
#define SYS_CLOCK_HZ 50000000  // Assume 50 MHz system clock
#define UART_BASE_ADDR 0x10000000  // UART base address
#define UART_BAUD_RATE 9600
#define SYS_TICK_FREQUENCY 1000  // SysTick at 1ms interval

// Setup the system clock for proper timing and task scheduling
void setup_clock() {
    // Configure the PLL, assuming fixed 50 MHz for simplicity
    // In actual implementation, this should set up the PLL registers and clock sources
    // configure_pll(SYS_CLOCK_HZ); // Configure PLL to 50 MHz
    // enable_clock_source();       // Enable clock source
}

// Initialize GPIO pins for UART or other peripheral I/O
void init_gpio() {
    // Enable GPIO pins for UART (TX and RX)
    GPIO_EnablePin(0, GPIO_MODE_OUTPUT);  // UART TX pin
    GPIO_EnablePin(1, GPIO_MODE_INPUT);   // UART RX pin
}

// Initialize UART for debugging/logging
void init_uart() {
    // Initialize UART at the given base address
    UART_Init(UART_BASE_ADDR);
    UART_SetBaudRate(UART_BASE_ADDR, UART_BAUD_RATE);
    UART_Enable(UART_BASE_ADDR);
}

// Initialize system timer (SysTick) for context switching and task scheduling
void init_timer() {
    // Set up SysTick interrupt every 1 ms
    SysTick_Config(SYS_TICK_FREQUENCY);
}

// Initialize interrupt system and enable necessary interrupts
void init_interrupts() {
    // Enable global interrupts
    EnableInterrupts();

    // Enable SysTick interrupt for task scheduling (1ms tick)
    NVIC_EnableIRQ(SysTick_IRQn);
    
    // Enable UART interrupt for handling data reception
    NVIC_EnableIRQ(UART_IRQn);
}
