/* Copyright Andrew Parsons 2019 */

#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include "freertos_test.hpp"
#include "register_test.hpp"
#include "button_test.hpp"


void Button::read_button() {
  if (RegisterMock::read_input_value()) {
    RTOSMock::vTaskDelay(100);
    // xTaskNotify(xTaskHandle1, 0, eNoAction);
    RTOSMock::xTaskNotify(1, 0, 2);
  }
}

class ButtonTests: public testing::Test {
 public:
  Button button;

 protected:
  // void SetUp() override {}
  // void TearDown() override {}
};

TEST_F(ButtonTests, ButtonIsPressed) {
  // setup

  // expect
  EXPECT_CALL(button, read_input_value())
  .WillOnce(testing::Return(true));

  EXPECT_CALL(button, vTaskDelay(100))
  .Times(1);

  EXPECT_CALL(button, xTaskNotify(1, 0, 2))
  .Times(1);

  // run
  button.read_button();
}

TEST_F(ButtonTests, ButtonIsNotPressed) {
  // setup

  // expect
  EXPECT_CALL(button, read_input_value())
  .WillOnce(testing::Return(false));

  EXPECT_CALL(button, vTaskDelay(100))
  .Times(0);

  EXPECT_CALL(button, xTaskNotify(1, 0, 2))
  .Times(0);

  // run
  button.read_button();
}
