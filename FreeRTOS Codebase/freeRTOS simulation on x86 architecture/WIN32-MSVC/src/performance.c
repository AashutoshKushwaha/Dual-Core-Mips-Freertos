#include "performance.h"
#include "uart.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>  // Required for uint32_t and other fixed-width types

// Global variables for tracking task performance
TickType_t task_start_time, task_end_time;

// Benchmark task latency
void benchmark_task_latency() {
    task_start_time = xTaskGetTickCount();

    // Simulate task creation and execution
    create_task(benchmark_task, "Benchmark", 2);

    task_end_time = xTaskGetTickCount();
    
    uart_send("Task Latency: ");
    uart_send_int(task_end_time - task_start_time);
}

// Benchmark context switch latency
void benchmark_context_switch() {
    TickType_t context_switch_start = xTaskGetTickCount();

    // Simulate a context switch (using Windows thread-based task switching)
    // This will be triggered by FreeRTOS scheduling tasks
    
    context_switch_start = xTaskGetTickCount();
    
    uart_send("Context Switch Latency: ");
    uart_send_int(context_switch_start - task_start_time);
}

// Benchmark contention overhead (simulating mutex locking)
void benchmark_contention_overhead() {
    // Measure the contention overhead (time spent waiting for synchronization primitives)
    TickType_t contention_start = xTaskGetTickCount();
    
    // Simulate mutex locking (use FreeRTOS mutex)
    lock_mutex();
    TickType_t contention_end = xTaskGetTickCount();
    
    uart_send("Contention Overhead: ");
    uart_send_int(contention_end - contention_start);
}

// Simulate mutex locking
void lock_mutex() {
    // Lock a mutex or semaphore to simulate contention
    if (xSemaphoreTake(xSemaphore, portMAX_DELAY) == pdTRUE) {
        // Simulate critical section
        vTaskDelay(pdMS_TO_TICKS(500));  // Simulate some processing time
        xSemaphoreGive(xSemaphore);
    }
}
