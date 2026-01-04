// application_tasks.c
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "uart.h" // Simulating UART with printf
#include <stdint.h>  // Required for uint32_t and other fixed-width types

// Declare a global semaphore
SemaphoreHandle_t xSemaphore;

// Producer Task
void producer_task(void *pvParameters) {
    static int produced_item = 0;

    while(1) {
        // Produce an item (simple counter)
        produced_item++;

        // Log the produced item using printf (Windows console output)
        uart_send("Produced Item: ");
        uart_send_int(produced_item);

        // Synchronize using a semaphore
        if (xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE) {
            // Critical section - simulate work
            vTaskDelay(pdMS_TO_TICKS(1000)); // Simulate work
            xSemaphoreGive(xSemaphore);
        }

        vTaskDelay(pdMS_TO_TICKS(1000)); // Task delay (1 second)
    }
}

// Consumer Task
void consumer_task(void *pvParameters) {
    static int consumed_item = 0;

    while(1) {
        // Consume an item (simple counter)
        consumed_item++;

        // Log the consumed item using printf (Windows console output)
        uart_send("Consumed Item: ");
        uart_send_int(consumed_item);

        vTaskDelay(pdMS_TO_TICKS(1500)); // Task delay (1.5 seconds)
    }
}

// Task setup function
void setup_tasks() {
    // Initialize semaphore
    xSemaphore = xSemaphoreCreateMutex(); // or xSemaphoreCreateBinary();
    if (xSemaphore == NULL) {
        uart_send("Semaphore creation failed!\n"); // Handle error
    }

    // Create Producer and Consumer tasks
    xTaskCreate(producer_task, "Producer", 128, NULL, 2, NULL);  // Higher priority for producer
    xTaskCreate(consumer_task, "Consumer", 128, NULL, 1, NULL);  // Lower priority for consumer
}
