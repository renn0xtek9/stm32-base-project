/*! \file unit_test.cpp
\brief unit tests of probe library
*/

#include <device_handler.h>
#include <gtest/gtest.h>

/*! \test CheckDeviceFileExists_DoesNotThrow
 * \brief Check that the Probe function does not throw
 */
TEST(CheckDeviceFileExists, NoThrow) {
  EXPECT_NO_THROW(CheckDeviceFileExists("/dev/not_a_real_device"));
}
