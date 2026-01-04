// gpio.c
#include <stdio.h>
#include "gpio.h"  // Include the header for proper function declaration

// Define the function that sets a GPIO pin high (simulated)
void gpio_set_pin(uint32_t pin) {
    // Simulate setting a GPIO pin high by printing to the console
    printf("GPIO Pin %d set HIGH\n", pin);
}

// Define the function that clears a GPIO pin (simulated)
void gpio_clear_pin(uint32_t pin) {
    // Simulate setting a GPIO pin low
    printf("GPIO Pin %d set LOW\n", pin);
}
