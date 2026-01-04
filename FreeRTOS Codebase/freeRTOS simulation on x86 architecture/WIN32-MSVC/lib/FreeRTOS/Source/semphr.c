// semphr.c
#include "FreeRTOS.h"
#include "semphr.h"
#include "task.h"
#include <stdint.h>  // Required for uint32_t and other fixed-width types

// Create a semaphore or mutex (depending on type)
SemaphoreHandle_t xSemaphoreCreateBinary(void) {
    return xQueueCreate(1, sizeof( uint8_t ));
}

// Take a semaphore (block the task until available)
BaseType_t xSemaphoreTake(SemaphoreHandle_t xSemaphore, TickType_t xBlockTime) {
    // Check if the semaphore is available and block the task
    return xQueueReceive(xSemaphore, NULL, xBlockTime);
}

// Give a semaphore (release it for other tasks to use)
BaseType_t xSemaphoreGive(SemaphoreHandle_t xSemaphore) {
    return xQueueSend(xSemaphore, NULL, 0);
}

// Mutex creation (binary semaphore with ownership tracking)
SemaphoreHandle_t xSemaphoreCreateMutex(void) {
    return xQueueCreate(1, sizeof( uint8_t ));
}

// Take a mutex (block until available, with priority inheritance)
BaseType_t xSemaphoreTakeMutex(SemaphoreHandle_t xSemaphore, TickType_t xBlockTime) {
    return xSemaphoreTake(xSemaphore, xBlockTime);
}

// Give a mutex (release it)
BaseType_t xSemaphoreGiveMutex(SemaphoreHandle_t xSemaphore) {
    return xSemaphoreGive(xSemaphore);
}
