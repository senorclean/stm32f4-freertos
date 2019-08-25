cmake_minimum_required(VERSION 3.6)
project (stm32f4_test CXX)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}")
set(PROJ_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../")
set(CMAKE_CXX_FLAGS "-fno-rtti -fno-builtin -Wall -std=gnu++11 -fdata-sections -ffunction-sections -g -O0")

# find_package(PkgConfig)
# pkg_check_modules(GTEST "gtest" REQUIRED)
# pkg_check_modules(GMOCK "gmock" REQUIRED)
enable_testing()
find_package(GTest REQUIRED)
find_package(GMock REQUIRED)

file(GLOB USER_SRCS ${USER_SRCS} "${PROJ_DIR}/src/*.cpp")

include_directories(${GTEST_INCLUDE_DIRS} ${GMOCK_INCLUDE_DIRS} ${PROJ_DIR}/inc)

add_executable(${PROJECT_NAME} ${USER_SRCS})
target_link_libraries(${PROJECT_NAME} ${GTEST_LIBRARIES} ${GMOCK_LIBRARIES} pthread)

add_custom_target(mr_clean
  COMMAND rm CMakeCache.txt
  COMMAND rm -r CMakeFiles
  COMMAND rm -r cmake_install.cmake
  COMMENT "Cleaning build directory"
)