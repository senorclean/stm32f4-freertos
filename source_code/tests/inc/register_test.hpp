/* Copyright Andrew Parsons 2019 */

#ifndef TESTS_INC_REGISTER_TEST_HPP_
#define TESTS_INC_REGISTER_TEST_HPP_

#include <gmock/gmock.h>

class RegisterMock {
 public:
  MOCK_METHOD0(read_input_value, bool());
};

#endif  // TESTS_INC_REGISTER_TEST_HPP_
