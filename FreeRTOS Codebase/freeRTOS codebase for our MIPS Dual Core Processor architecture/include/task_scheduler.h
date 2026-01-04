#ifndef TASK_SCHEDULER_H
#define TASK_SCHEDULER_H

void scheduler_init(void);
void create_task(void (*task_function)(void *), const char *name, uint32_t priority);
void start_scheduler(void);

#endif
