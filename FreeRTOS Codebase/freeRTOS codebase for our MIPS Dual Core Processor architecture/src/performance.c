// performance.c
#include "performance.h"
#include "uart.h"
#include "FreeRTOS.h"
#include "task.h"

// Global variables for tracking task performance
TickType_t task_start_time, task_end_time;

void benchmark_task_latency() {
    task_start_time = xTaskGetTickCount();

    // Simulate task creation and execution
    create_task(benchmark_task, "Benchmark", 2);

    task_end_time = xTaskGetTickCount();
    
    uart_send("Task Latency: ");
    uart_send_int(task_end_time - task_start_time);
}

void benchmark_context_switch() {
    TickType_t context_switch_start = xTaskGetTickCount();

    // Simulate a context switch
    // This can be tracked with FreeRTOS hooks or a custom timer
    
    context_switch_start = xTaskGetTickCount();
    
    uart_send("Context Switch Latency: ");
    uart_send_int(context_switch_start - task_start_time);
}

void benchmark_contention_overhead() {
    // Measure the contention overhead (time spent waiting for synchronization primitives)
    TickType_t contention_start = xTaskGetTickCount();
    
    // Simulate mutex locking
    lock_mutex();
    TickType_t contention_end = xTaskGetTickCount();
    
    uart_send("Contention Overhead: ");
    uart_send_int(contention_end - contention_start);
}
