/*! \file unit_test.cpp
\brief unit tests of probe library
*/
#include <device_handler/device_handler.h>
#include <fcntl.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "utils.h"

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

/*! \test OpenDeviceFileTest Success
 * \brief Check opening of file devie with success
 */
TEST_F(OpenDeviceFileTest, OpenFileSuccess) {
  EXPECT_CALL(mock_file_operations, open(::testing::_, O_RDWR | O_NOCTTY | O_SYNC)).WillOnce(::testing::Return(5));

  int result = OpenDeviceFile("/dev/some_file",
                              [this](const char* path, int flags) { return mock_file_operations.open(path, flags); });

  EXPECT_EQ(result, 5);
}

/*! \test OpenDeviceFileTest Failure
 * \brief Check opening of file devie with failure
 */
TEST_F(OpenDeviceFileTest, OpenFileFailure) {
  EXPECT_CALL(mock_file_operations, open(::testing::_, O_RDWR | O_NOCTTY | O_SYNC)).WillOnce(::testing::Return(-1));

  int result = OpenDeviceFile("/dev/some_file",
                              [this](const char* path, int flags) { return mock_file_operations.open(path, flags); });

  EXPECT_EQ(result, -1);
}
