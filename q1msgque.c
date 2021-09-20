#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

QueueHandle_t intmq;
void first_task(void *data)
{
    while(1)
    {
        printf(" task1 start \n");

        printf(" task1 finish \n");
        vTaskDelay(1000/ portTICK_PERIOD_MS);

    }
}

void second_task(void *data)
{
    while(1)
    {
        printf(" task2 start \n");
        
        printf(" task2 finish \n");
        vTaskDelay(2000/ portTICK_PERIOD_MS);

    }
}

void third_task(void *data)
{
    while(1)
    {
        printf(" task3 start \n");
        
        printf(" task3 finish \n");
        vTaskDelay(5000/ portTICK_PERIOD_MS);

    }
}




void fourth_task(void *data)
{
    int integer = 50;
    while(1)
    {
        printf(" task4 start \n");
        
        
        printf(" task4 finish \n");
        xQueueSend(intmq,&integer, 0);
        vTaskDelay(3000/ portTICK_PERIOD_MS);

    }
}


void tfifth_task(void *data)
{
    int buf;
    
    while(1)
    {
        printf("task5 start \n");
        xQueueReceive(intmq,&buf, 0);
        printf("integer from task4 is: %d\n",buff);
    
        printf(" task5 finish \n");
        vTaskDelay(3000/ portTICK_PERIOD_MS);
      
      
    }
   
}



void app_main(void)
{
    xTaskCreate(first_task, "first_tsk", 2048, NULL, 10, NULL);
    xTaskCreate(second_task, "second_tsk", 2048, NULL, 8, NULL);
    xTaskCreate(third_task, "third_tsk", 2048, NULL, 6, NULL);
    xTaskCreate(fourth_task, "fourth_tsk", 2048, NULL, 5, NULL);
    xTaskCreate(fifth_task, "fifth_tsk", 2048, NULL, 3, NULL);
    intmq = xQueueCreate(3, sizeof(int));
   
}

