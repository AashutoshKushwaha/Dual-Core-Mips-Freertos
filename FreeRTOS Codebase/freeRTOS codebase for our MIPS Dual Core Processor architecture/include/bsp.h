#ifndef BSP_H
#define BSP_H

void bsp_init(void);
void setup_clock(void);
void init_gpio(void);
void init_uart(void);
void init_timer(void);
void init_interrupts(void);

#endif
