// main.c
#include "FreeRTOS.h"
#include "task.h"
#include "application_tasks.h"  // Include your tasks header file
#include <stdint.h>  // Required for uint32_t and other fixed-width types

int main(void) {
    // Initialize the tasks (Producer, Consumer, etc.)
    setup_tasks();  // Function to create tasks

    // Start the FreeRTOS scheduler
    vTaskStartScheduler();

    // The scheduler takes control, so this part will never be reached
    while (1) {
        // This is an idle loop: FreeRTOS will take over
    }
}
