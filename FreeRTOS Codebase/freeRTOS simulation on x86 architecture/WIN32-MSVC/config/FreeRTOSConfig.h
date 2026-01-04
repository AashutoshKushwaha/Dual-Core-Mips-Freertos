// FreeRTOSConfig.h
#define configUSE_PREEMPTION                1
#define configUSE_IDLE_HOOK                 1
#define configUSE_TICK_HOOK                 1
#define configMAX_PRIORITIES                5
#define configMINIMAL_STACK_SIZE           128  // Adjust if needed (256 or 512 bytes for more complex tasks)
#define configTOTAL_HEAP_SIZE              ( 10 * 1024 )  // Keep as 10 KB (increase if necessary)
#define configMAX_TASK_NAME_LEN            16
#define configUSE_TIME_SLICING             1
#define configTICK_RATE_HZ                 ( ( TickType_t ) 1000 )  // 1ms tick rate
#define configCPU_CLOCK_HZ                 ( ( unsigned long ) 100000000 ) // 100 MHz for Windows simulation
