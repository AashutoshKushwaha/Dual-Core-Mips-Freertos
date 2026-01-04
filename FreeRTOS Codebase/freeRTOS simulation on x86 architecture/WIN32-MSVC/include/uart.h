#ifndef UART_H
#define UART_H

#include <stdint.h>  // Required for uint32_t and other fixed-width types

// Function Declarations

/**
 * @brief Initialize the UART interface with a given base address
 *
 * @param base_addr The base address of the UART peripheral (e.g., memory-mapped I/O address)
 */
void UART_Init(uint32_t base_addr);

/**
 * @brief Send a single character via UART
 *
 * @param base_addr The base address of the UART peripheral
 * @param ch The character to send
 */
void UART_SendChar(uint32_t base_addr, char ch);

/**
 * @brief Receive a single character via UART
 *
 * @param base_addr The base address of the UART peripheral
 * @return char The received character
 */
char UART_ReceiveChar(uint32_t base_addr);

/**
 * @brief Send a string via UART
 *
 * @param base_addr The base address of the UART peripheral
 * @param str The string to send
 */
void UART_SendString(uint32_t base_addr, const char* str);

/**
 * @brief UART interrupt handler (optional, for handling UART interrupts)
 */
void UART_IRQHandler(void);

#endif // UART_H
x