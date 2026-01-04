// task_scheduler.h
#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

#include <stdint.h>  // Required for uint32_t and other fixed-width types

// Function Prototypes
void scheduler_init(void);
void create_task(void (*task_function)(void*), const char* name, uint32_t priority);
void start_scheduler(void);

#endif // TASK_SCHEDULER_H
