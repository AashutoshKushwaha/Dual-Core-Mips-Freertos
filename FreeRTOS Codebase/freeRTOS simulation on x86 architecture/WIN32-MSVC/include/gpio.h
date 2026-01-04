// gpio.h
#ifndef GPIO_H
#define GPIO_H

#include <stdint.h>  // Required for uint32_t

// Function prototypes
void gpio_set_pin(uint32_t pin);
void gpio_clear_pin(uint32_t pin);

#endif /* GPIO_H */
