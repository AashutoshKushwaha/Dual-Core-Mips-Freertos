#ifndef GPIO_H
#define GPIO_H

// GPIO Modes
#define GPIO_MODE_INPUT      0
#define GPIO_MODE_OUTPUT     1

void GPIO_EnablePin(uint32_t pin, uint32_t mode);
void GPIO_SetPin(uint32_t pin);
void GPIO_ClearPin(uint32_t pin);
uint32_t GPIO_ReadPin(uint32_t pin);

#endif
