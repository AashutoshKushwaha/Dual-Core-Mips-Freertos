// portmacro.h

#ifndef PORTMACRO_H
#define PORTMACRO_H

#include "FreeRTOS.h"
#include "task.h"

// Windows-specific types
#define portCHAR                char
#define portFLOAT               float
#define portDOUBLE              double
#define portLONG                long
#define portSHORT               short
#define portSTACK_TYPE          uint32_t
#define portBASE_TYPE           long

typedef portSTACK_TYPE StackType_t;
typedef long BaseType_t;
typedef unsigned long UBaseType_t;

// TickType_t is the type used for FreeRTOS ticks (32-bit)
typedef uint32_t TickType_t;
#define portMAX_DELAY           ( TickType_t ) 0xffffffffUL
#define portTICK_PERIOD_MS      ( ( TickType_t ) 1000 / configTICK_RATE_HZ )

// For Windows, we use 8-byte alignment for stack (standard for 64-bit systems)
#define portBYTE_ALIGNMENT      8

// Stack growth is downwards for Windows
#define portSTACK_GROWTH        -1

// Critical section management macros (using Windows API functions)
#define portENTER_CRITICAL()    taskENTER_CRITICAL()
#define portEXIT_CRITICAL()     taskEXIT_CRITICAL()

// Context switching macro (no need for assembly here)
#define portTASK_FUNCTION_PROTO( vFunction, pvParameters )  \
            void vFunction( void *pvParameters ) __attribute__((noreturn))
#define portTASK_FUNCTION( vFunction, pvParameters )        \
            void vFunction( void *pvParameters )

// This is to manage task yields in Windows
#define portEND_SWITCHING_ISR( xSwitchRequired )  \
if( xSwitchRequired )                             \
{                                                 \
    portYIELD();                                  \
}
#define portYIELD_FROM_ISR( x ) portEND_SWITCHING_ISR( x )

#endif  /* PORTMACRO_H */
