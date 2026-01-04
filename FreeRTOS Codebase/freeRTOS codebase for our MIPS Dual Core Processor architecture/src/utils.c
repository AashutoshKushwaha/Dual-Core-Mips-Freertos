// utils.c
#include "utils.h"
#include "uart.h"

void uart_send_int(int number) {
    char buffer[16];
    sprintf(buffer, "%d", number);
    uart_send(buffer);
}

void log_message(char *message) {
    uart_send(message);
}
