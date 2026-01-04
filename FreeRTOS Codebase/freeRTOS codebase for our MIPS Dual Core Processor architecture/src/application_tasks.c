// application_tasks.c
#include "application_tasks.h"
#include "FreeRTOS.h"
#include "task.h"
#include "intercore_communication.h"
#include "uart.h"

void producer_task(void *pvParameters) {
    int produced_item = 0;

    while(1) {
        // Produce an item (simple counter in this case)
        produced_item++;

        // Send the item to the consumer task via mailbox
        send_message_to_core(produced_item);

        // Log the produced item via UART
        uart_send("Produced Item: ");
        uart_send_int(produced_item);

        // Delay for simulation (1 second)
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void consumer_task(void *pvParameters) {
    int consumed_item = 0;

    while(1) {
        // Wait for a message from the producer task
        consumed_item = receive_message_from_core();

        // Consume the item (simply log it)
        uart_send("Consumed Item: ");
        uart_send_int(consumed_item);

        // Delay for simulation (1.5 seconds)
        vTaskDelay(pdMS_TO_TICKS(1500));
    }
}
