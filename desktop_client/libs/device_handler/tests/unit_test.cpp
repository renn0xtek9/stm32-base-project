/*! \file unit_test.cpp
\brief unit tests of probe library
*/

#include <device_handler/device_handler.h>
#include <gtest/gtest.h>

/*! \test CheckDeviceFileExists_DoesNotThrowIfNotExisting
 * \brief Check that the function does not throw
 */
TEST(CheckDeviceFileExists, NoThrow) {
  EXPECT_NO_THROW(CheckDeviceFileExists("/dev/not_a_real_device"));
}

/*! \test CheckDeviceFileExists_ReturTrueIfExisting
 * \brief Check that the function return true if the file exists
 */
TEST(CheckDeviceFileExists, ReturnTrue) {
  EXPECT_TRUE(CheckDeviceFileExists("existing_file"));
}

/*! \test CheckDeviceFileExists_ReturFalseIfNotExisting
 * \brief Check that the function return false if the file does not exist
 */
TEST(CheckDeviceFileExists, ReturnFalse) {
  EXPECT_FALSE(CheckDeviceFileExists("/dev/not_a_real_device"));
}
