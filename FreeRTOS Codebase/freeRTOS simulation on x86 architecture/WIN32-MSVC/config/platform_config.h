#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

// System tick configuration (FreeRTOS tick rate)
#define SYS_TICK_FREQUENCY    1000  // 1kHz tick rate (1ms tick interval)

// UART configuration
#define UART_BAUD_RATE         9600  // Baud rate for UART (for console output simulation)
#define UART_BASE_ADDR          0x4000  // Base address for UART (for simulation, can be adjusted)

// CPU clock frequency (for simulation purposes)
#define CPU_CLOCK_HZ           100000000  // 100 MHz for Windows simulation (adjustable)

// Timer frequency for software timers in FreeRTOS
#define SIMULATION_TIMER_FREQUENCY 1000  // Optional: Define software timer frequency for simulation (1ms)

#endif // PLATFORM_CONFIG_H
