/* Copyright Andrew Parsons 2019 */

#ifndef TESTS_INC_FREERTOS_TEST_HPP_
#define TESTS_INC_FREERTOS_TEST_HPP_

#include <gmock/gmock.h>

class RTOSMock {
 public:
  MOCK_METHOD1(vTaskDelay, void(int delay));
  MOCK_METHOD3(xTaskNotify, void(int handle, int value, int incr));
};

#endif  // TESTS_INC_FREERTOS_TEST_HPP_
