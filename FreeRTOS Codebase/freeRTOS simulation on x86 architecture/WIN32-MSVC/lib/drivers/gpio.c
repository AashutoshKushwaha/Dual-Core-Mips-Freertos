// gpio.c
#include <stdio.h>

void gpio_set_pin(uint32_t pin) {
    // Simulate setting a GPIO pin high by printing to the console
    printf("GPIO Pin %d set HIGH\n", pin);
}

void gpio_clear_pin(uint32_t pin) {
    // Simulate setting a GPIO pin low
    printf("GPIO Pin %d set LOW\n", pin);
}
