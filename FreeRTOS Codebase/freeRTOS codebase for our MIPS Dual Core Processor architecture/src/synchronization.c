// synchronization.c
#include "synchronization.h"
#include "FreeRTOS.h"
#include "semphr.h"

// Declare a global mutex
SemaphoreHandle_t xMutex;

void init_semaphores() {
    // Create a mutex for synchronization between tasks
    xMutex = xSemaphoreCreateMutex();
}

void lock_mutex() {
    // Lock the mutex to protect shared resources
    xSemaphoreTake(xMutex, portMAX_DELAY);
}

void release_mutex() {
    // Release the mutex after accessing shared resources
    xSemaphoreGive(xMutex);
}
