#include <stdint.h>
//#include <cstdint.h>
#include "FreeRTOS.h"
#include "task.h"
//#include "stm32f4xx.h"
#include "gpio.h"
#include "reg_access.h"
#include "rcc.h"
#include "dwt.h"

/***** Definitions ***********************************************************/
#define HSE_VALUE ((uint32_t)8000000)


TaskHandle_t xTaskHandle1 = NULL;
TaskHandle_t xTaskHandle2 = NULL;

void vTask1_handler(void *params);
void vTask2_handler(void *params);

void vTaskLED(void *pvParameters);

typedef port_pin< u32, u32, GPIOD, u32(PIN13)> port_d13;

/***** Main Loop *************************************************************/
int main() {
  // enable counter so segger systemview has timestamps for events
  //reg_access<u32, u32, DWT_DEMCR, u32(BIT_POS(24))>::reg_or();
  reg_access<u32, u32, DWT_CYCCNT, 0>::reg_set();
  reg_access<u32, u32, DWT_CTRL, u32(DWT_CTRL_CYCCNTENA)>::reg_or();

  // GPIOD clock
  reg_access< u32, u32, RCC_AHB1ENR, u32(RCC_AHB1ENR_IOPDEN)>::reg_or();
  // GPIOA clock
  reg_access< u32, u32, RCC_AHB1ENR, u32(RCC_AHB1ENR_IOPAEN)>::reg_or();

  SEGGER_SYSVIEW_Conf();
  SEGGER_SYSVIEW_Start();

  //xTaskCreate(vTask1_handler, "task1", configMINIMAL_STACK_SIZE, NULL, 2, &xTaskHandle1);
  xTaskCreate(vTask1_handler, "task1", 500, NULL, 2, &xTaskHandle1);
  xTaskCreate(vTask2_handler, "task2", 500, NULL, 2, &xTaskHandle2);

  // LED 0 - 3: PD12 - 15
  // BUTTON: PA0

  typedef port_pin< u32, u32, GPIOD, u32(PIN12)> port_d12;

  reg_access< u32, u32, GPIO_ODR(GPIOD), u32(GPIO12)>::reg_or();

  typedef port_pin< u32, u32, GPIOA, u32(PIN0)> port_a0;

  port_a0::set_direction_input();
  port_d12::set_direction_output();
  port_d13::set_direction_output();

  vTaskStartScheduler();

  while(1);
}

void vTask1_handler(void *params)
{
  uint32_t notif_value = 0;
  while(1) {
    if (xTaskNotifyWait(0, 0, &notif_value, portMAX_DELAY) == pdTRUE) {
      port_d13::toggle();
    }
  }
}

void vTask2_handler(void *params)
{
  bool val;
  while(1) {
    val = reg_access< u32, u32, GPIO_IDR(GPIOA), u32(PIN0)>::bit_get();
    if (val & BIT_POS(0)) {
      vTaskDelay(100 / portTICK_PERIOD_MS);
      //xTaskNotify(xTaskHandle1, 0, eNoAction);
      xTaskNotify(xTaskHandle1, 0, eIncrement);
    }
  }
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
