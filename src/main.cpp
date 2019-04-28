#include <stdint.h>
#include "FreeRTOS.h"
#include "task.h"
#include "stm32f4xx.h"
//#include "gpio.h"

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
int main() {
  // enable counter so segger systemview has timestamps for events
  DWT_DEMCR |= (1 << 24);
  DWT_CYCCNT = 0;
  DWT_CONTROL |= (1 << 0);

  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();

  xTaskCreate(vTask1_handler, "task1", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle1);
  xTaskCreate(vTask2_handler, "task2", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle2);

  // typedef reg_access< std::uint32_t,
  //                     std::uint32_t,
  //                     0x40020C00,
  //                     UINT32_C(12)> portd_dir;

  // portd_dir::bit_set();

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

extern "C" void vApplicationTickHook() {

}

extern "C" void vApplicationMallocFailedHook() {

}

extern "C" void vApplicationIdleHook() {

}

extern "C" void vApplicationStackOverflowHook() {

}

extern "C" void vApplicationGetIdleTaskMemory() {

}

extern "C" void vApplicationGetTimerTaskMemory() {

}
