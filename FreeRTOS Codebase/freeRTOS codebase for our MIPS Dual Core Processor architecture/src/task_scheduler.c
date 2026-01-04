// task_scheduler.c
#include "task_scheduler.h"
#include "FreeRTOS.h"
#include "task.h"

void scheduler_init() {
    // Initialize the FreeRTOS scheduler
    // Multi-core scheduling handled automatically by FreeRTOS port
    // Core-specific tasks can be created in this function
}

void create_task(void (*task_function)(void *), const char *name, uint32_t priority) {
    // Create tasks for different cores (simplified for single core in FreeRTOS)
    xTaskCreate(task_function, name, configMINIMAL_STACK_SIZE, NULL, priority, NULL);
}

void start_scheduler() {
    // Start the FreeRTOS scheduler, initiating task switching
    vTaskStartScheduler();
}
