#include "FreeRTOS.h"
#include "task.h"
#include "platform_config.h"
#include "port.h"
#include <windows.h>
#include <stdint.h>  // Required for uint32_t and other fixed-width types

// Global variable for interrupt nesting
volatile UBaseType_t uxInterruptNesting = 0x0;

// Windows timer to simulate SysTick interrupt
static UINT_PTR timerID = 0;

// Task context management (Windows doesn't need assembly-based context switching)
StackType_t* pxPortInitialiseStack(StackType_t* pxTopOfStack, TaskFunction_t pxCode, void* pvParameters) {
    // Set up the initial stack frame for a new task
    *pxTopOfStack = (StackType_t)0xDEADBEEF;  // Task stack marker
    pxTopOfStack--;

    *pxTopOfStack = (StackType_t)0x12345678;  // Return address after task switch
    pxTopOfStack--;

    // Push the function address and parameters onto the stack
    *pxTopOfStack = (StackType_t)pxCode;
    pxTopOfStack--;

    *pxTopOfStack = (StackType_t)pvParameters;
    pxTopOfStack--;

    return pxTopOfStack;
}

// Start the FreeRTOS scheduler
BaseType_t xPortStartScheduler(void) {
    // Initialize the Windows timer (to simulate SysTick interrupt every 1ms)
    timerID = SetTimer(NULL, 0, 1, (TIMERPROC)vPortIncrementTick);

    // Start the first task
    vPortStartFirstTask();

    // Control will not return here
    return pdFALSE;
}

// Timer callback for simulating SysTick interrupt
void CALLBACK vPortIncrementTick(HWND hwnd, UINT uMsg, UINT_PTR idEvent, DWORD dwTime) {
    BaseType_t xHigherPriorityTaskWoken = pdFALSE;

    // Increment the tick count and trigger a context switch if necessary
    if (xTaskIncrementTick() != pdFALSE) {
        portYIELD();
    }

    // Look for the ISR stack getting near or past its limit (for debugging purposes)
    portCHECK_ISR_STACK();

    // Clear the timer interrupt
    KillTimer(NULL, timerID);
    timerID = SetTimer(NULL, 0, 1, (TIMERPROC)vPortIncrementTick);
}

// Create the first task
void vPortStartFirstTask(void) {
    // Retrieve the stack pointer for the first task
    TaskHandle_t pxCurrentTask = xTaskGetCurrentTaskHandle();
    uxSavedTaskStackPointer = (UBaseType_t)pxCurrentTask;

    // Start the first task (task switch logic)
    // This will cause FreeRTOS to start task switching
    vTaskStartScheduler();
}

// Task yield function
void vPortYieldISR(void) {
    // Trigger a context switch (using Windows threads)
    portYIELD();
}
