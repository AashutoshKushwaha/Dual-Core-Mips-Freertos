// uart.c
#include <stdio.h>
#include <stdint.h>  // Required for uint32_t and other fixed-width types

void uart_send(const char *message) {
    // Simulate UART using printf (prints to Windows console)
    printf("%s", message);
}

void uart_send_int(int num) {
    // Simulate UART with integer printing
    printf("%d\n", num);
}
