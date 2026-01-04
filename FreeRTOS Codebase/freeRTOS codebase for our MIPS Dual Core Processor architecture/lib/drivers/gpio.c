// gpio.c
#include "gpio.h"
#include "FreeRTOS.h"
#include "task.h"

// Example GPIO register base address
#define GPIO_BASE_ADDR        0x20000000  // Example GPIO base address
#define GPIO_PIN_DIR_REG      *((volatile unsigned int *)(GPIO_BASE_ADDR + 0x00))  // Direction Register
#define GPIO_PIN_DATA_REG     *((volatile unsigned int *)(GPIO_BASE_ADDR + 0x04))  // Data Register

// Function to configure a GPIO pin as input or output
void GPIO_EnablePin(uint32_t pin, uint32_t mode) {
    // Configure pin direction (0 = input, 1 = output)
    if (mode == GPIO_MODE_OUTPUT) {
        GPIO_PIN_DIR_REG |= (1 << pin);  // Set pin as output
    } else {
        GPIO_PIN_DIR_REG &= ~(1 << pin); // Set pin as input
    }
}

// Function to set a GPIO pin high
void GPIO_SetPin(uint32_t pin) {
    GPIO_PIN_DATA_REG |= (1 << pin);  // Set pin to high
}

// Function to set a GPIO pin low
void GPIO_ClearPin(uint32_t pin) {
    GPIO_PIN_DATA_REG &= ~(1 << pin);  // Set pin to low
}

// Function to read a GPIO pin (returns 1 if high, 0 if low)
uint32_t GPIO_ReadPin(uint32_t pin) {
    return (GPIO_PIN_DATA_REG & (1 << pin)) ? 1 : 0;
}
