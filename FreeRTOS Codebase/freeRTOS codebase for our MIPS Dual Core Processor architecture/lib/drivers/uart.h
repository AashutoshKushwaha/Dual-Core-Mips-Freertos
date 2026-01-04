#ifndef UART_H
#define UART_H

void UART_Init(uint32_t base_addr);
void UART_SendChar(uint32_t base_addr, char ch);
char UART_ReceiveChar(uint32_t base_addr);
void UART_SendString(uint32_t base_addr, const char *str);
void UART_IRQHandler(void);  // Optional, for handling UART interrupts

#endif
