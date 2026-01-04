// uart.c
#include "uart.h"
#include "FreeRTOS.h"
#include "task.h"

// UART register addresses (Modify based on your hardware)
#define UART0_BASE_ADDR   0x10000000   // Example base address for UART0
#define UART_DR_REG       *((volatile unsigned int *)(UART0_BASE_ADDR + 0x00)) // Data Register
#define UART_FR_REG       *((volatile unsigned int *)(UART0_BASE_ADDR + 0x18)) // Flag Register
#define UART_IBRD_REG     *((volatile unsigned int *)(UART0_BASE_ADDR + 0x24)) // Integer Baud Rate Divisor
#define UART_FBRD_REG     *((volatile unsigned int *)(UART0_BASE_ADDR + 0x28)) // Fractional Baud Rate Divisor
#define UART_LCRH_REG     *((volatile unsigned int *)(UART0_BASE_ADDR + 0x2C)) // Line Control Register
#define UART_CR_REG       *((volatile unsigned int *)(UART0_BASE_ADDR + 0x30)) // Control Register
#define UART_IMSC_REG     *((volatile unsigned int *)(UART0_BASE_ADDR + 0x38)) // Interrupt Mask Set/Clear Register
#define UART_ICR_REG      *((volatile unsigned int *)(UART0_BASE_ADDR + 0x44)) // Interrupt Clear Register

// Function to initialize the UART peripheral
void UART_Init(uint32_t base_addr) {
    // Set baud rate: Here we assume a baud rate of 9600 and a system clock of 50 MHz
    unsigned int baud_rate = 9600;
    unsigned int integer_divisor = (50000000 / (16 * baud_rate));
    unsigned int fractional_divisor = (((50000000 % (16 * baud_rate)) * 64) + baud_rate / 2) / baud_rate;

    UART_IBRD_REG = integer_divisor;
    UART_FBRD_REG = fractional_divisor;

    // Configure UART for 8 data bits, no parity, 1 stop bit
    UART_LCRH_REG = (1 << 5) | (1 << 6);  // 8-bit data, enable FIFO

    // Enable UART, transmit, and receive
    UART_CR_REG = (1 << 0) | (1 << 8) | (1 << 9);  // UART, TX, RX enabled
}

// Function to send a character over UART
void UART_SendChar(uint32_t base_addr, char ch) {
    // Wait for UART to be ready to transmit
    while (UART_FR_REG & (1 << 5));  // Check if the Transmit FIFO is full (bit 5)

    // Send the character
    UART_DR_REG = ch;
}

// Function to receive a character over UART
char UART_ReceiveChar(uint32_t base_addr) {
    // Wait for data to be available
    while (UART_FR_REG & (1 << 4));  // Check if Receive FIFO is empty (bit 4)

    // Read received character
    return (char) UART_DR_REG;
}

// Function to send a string over UART
void UART_SendString(uint32_t base_addr, const char *str) {
    while (*str) {
        UART_SendChar(base_addr, *str++);
    }
}

// UART Interrupt Handler (optional)
void UART_IRQHandler(void) {
    // Check if interrupt is due to data received
    if (UART_FR_REG & (1 << 4)) {
        // Read received data and process it
        char received_char = UART_ReceiveChar(UART0_BASE_ADDR);

        // Process the received character (e.g., add to a buffer or handle command)
        uart_receive_char(received_char);
    }

    // Clear the interrupt flags
    UART_ICR_REG = 0xFF;
}
