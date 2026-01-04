#include "utils.h"
#include "uart.h"  // Ensure that uart functions are included

void uart_send_int(int number) {
    char buffer[16];
    sprintf(buffer, "%d", number);
    UART_SendString(0x4000, buffer);  // Assuming base address is 0x4000, modify as necessary
}

void log_message(char* message) {
    UART_SendString(0x4000, message);  // Assuming base address is 0x4000, modify as necessary
}
