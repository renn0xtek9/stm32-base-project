// Copyright 2024 <Maxime Haselbauer>
/*! \file unit_test.cpp
 * \brief unit tests of device handler library
 */
#include <device_handler/device_handler.h>
#include <fcntl.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "fixtures.h"

/*! \test HandleDevice Returns true if file is not found
 */
TEST_F(HandleDeviceFileTest, DeviceFileNotFoundReturnTrue) {
  DeviceHandler device_handler{os_abstraction_layer_};
  EXPECT_TRUE(device_handler.HandleDevice("/dev/not_a_real_device"));
}

/*! \test HandleDevice Returns false if file is found and we can open it
 */
TEST_F(HandleDeviceFileTest, DeviceFileFoundAndReturnFalse) {
  DeviceHandler device_handler{os_abstraction_layer_};
  EXPECT_FALSE(device_handler.HandleDevice("existing_file"));
}
