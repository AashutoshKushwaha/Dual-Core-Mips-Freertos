#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

#define configUSE_PREEMPTION                1
#define configUSE_IDLE_HOOK                 1
#define configUSE_TICK_HOOK                 1
#define configMAX_PRIORITIES                5
#define configMINIMAL_STACK_SIZE           128
#define configTOTAL_HEAP_SIZE              ( 10 * 1024 )
#define configMAX_TASK_NAME_LEN            16
#define configUSE_TIME_SLICING             1
#define configCPU_CLOCK_HZ                 ( ( unsigned long ) 50000000 )  // 50 MHz
#define configTICK_RATE_HZ                 ( ( TickType_t ) 1000 )        // 1ms tick

#endif
