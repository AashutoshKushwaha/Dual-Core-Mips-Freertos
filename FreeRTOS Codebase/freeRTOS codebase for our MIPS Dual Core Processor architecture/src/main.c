// main.c
#include "FreeRTOS.h"
#include "task.h"
#include "bsp.h"
#include "task_scheduler.h"
#include "application_tasks.h"
#include "interrupt_handlers.h"
#include "performance.h"

int main(void) {
    // Initialize the Board Support Package (BSP)
    bsp_init();
    
    // Initialize FreeRTOS scheduler
    scheduler_init();

    // Create tasks (producer-consumer workload for multi-core utilization)
    create_task(producer_task, "Producer", 1);
    create_task(consumer_task, "Consumer", 1);

    // Start the FreeRTOS scheduler
    start_scheduler();

    // This part will never be reached if the scheduler starts
    while (1) {
        // Run system idle loop or low power mode
    }
}
