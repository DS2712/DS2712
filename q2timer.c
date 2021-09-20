#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/timers.h"

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

void *const timer_id;
TimerHandle_t timer_handle;
void task3(void *para)
{
    timer_handle = xTimerCreate("timer",(10000 / portTICK_PERIOD_MS),pdFALSE,timer_id, callback);

    xTimerStart(my_timer_handle, 1);
    while (1)
    {
        printf("task3\n");
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }
}
void callback(TimerHandle_t xTimer)
{
    printf("Callback\n");
}




void app_main(void)
{
    xTaskCreate(first_task, "first_tsk", 2048, NULL, 10, NULL);
    xTaskCreate(second_task, "second_tsk", 2048, NULL, 8, NULL);
    xTaskCreate(third_task, "third_tsk", 2048, NULL, 6, NULL);
    
   
}

