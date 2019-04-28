#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx.h"

/***** Definitions ***********************************************************/
#define HSE_VALUE ((uint32_t)8000000)

#define DWT_CONTROL (*(volatile uint32_t *)0xE0001000)
#define DWT_CYCCNT  (*(volatile uint32_t *)0xE0001004)
#define DWT_DEMCR   (*(volatile uint32_t *)0xE000EDFC)


TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;

void vTask1_handler(void *params);
void vTask2_handler(void *params);

void vTaskLED(void *pvParameters);

/***** Main Loop *************************************************************/
int main(void) {
  // enable counter so segger systemview has timestamps for events
  DWT_DEMCR |= (1 << 24);
  DWT_CYCCNT = 0;
  DWT_CONTROL |= (1 << 0);

  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();

  xTaskCreate(vTask1_handler, "task1", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle1);
  xTaskCreate(vTask2_handler, "task2", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle2);

  vTaskStartScheduler();
  while(1);
}

void vTask1_handler(void *params)
{
  while(1);
}

void vTask2_handler(void *params)
{
  while(1);
}

void vApplicationTickHook(void) {

}

void vApplicationMallocFailedHook(void) {

}

void vApplicationIdleHook() {

}

void vApplicationStackOverflowHook() {

}

void vApplicationGetIdleTaskMemory() {

}

void vApplicationGetTimerTaskMemory() {

}
