/* Copyright Andrew Parsons 2019 */

#ifndef TESTS_INC_BUTTON_TEST_HPP_
#define TESTS_INC_BUTTON_TEST_HPP_

#include "freertos_test.hpp"
#include "register_test.hpp"

class Button : public RegisterMock, public RTOSMock {
 public:
  void read_button();
};

#endif  // TESTS_INC_BUTTON_TEST_HPP_


