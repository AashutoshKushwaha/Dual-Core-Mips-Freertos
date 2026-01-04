// task_scheduler.c
#include "task_scheduler.h"
#include "FreeRTOS.h"
#include "task.h"
#include <stdint.h>  // Required for uint32_t and other fixed-width types
#include <stdio.h>   // Required for printing error messages (optional)

void scheduler_init(void) {
    // Initialize the FreeRTOS scheduler
    // FreeRTOS automatically handles multi-core scheduling if supported by the platform
    // Core-specific tasks can be created here if needed for multi-core systems (e.g., using FreeRTOS for dual-core or SMP systems)

    printf("Scheduler initialized\n");
    // For single-core simulation, no additional initialization required
    // For multi-core systems, you may need to assign tasks to cores explicitly, FreeRTOS usually does this automatically
}

void create_task(void (*task_function)(void*), const char* name, uint32_t priority) {
    if (task_function == NULL) {
        printf("Error: Task function is NULL\n");
        return;
    }

    if (name == NULL) {
        name = "Unnamed Task";  // Default name if no name is provided
    }

    // Create task with FreeRTOS API
    BaseType_t result = xTaskCreate(task_function, name, configMINIMAL_STACK_SIZE, NULL, priority, NULL);

    if (result != pdPASS) {
        printf("Error: Failed to create task %s\n", name);
    }
    else {
        printf("Task %s created successfully with priority %d\n", name, priority);
    }
}

void start_scheduler(void) {
    // Start the FreeRTOS scheduler to begin task switching
    printf("Starting scheduler...\n");
    vTaskStartScheduler();
    // If control reaches here, it means the scheduler failed to start
    printf("Error: Scheduler failed to start\n");
}
