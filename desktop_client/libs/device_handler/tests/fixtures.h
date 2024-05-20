#ifndef FIXTURES_H
#define FIXTURES_H
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "mocks.h"

// class OsAbstractionLayerTestFixture :: pubic ::testing::Test {
//  public:
//   virtual ~OsAbstractionLayer() = default;
//   MockFileOperations mock_file_operations;
//   MockOpenDeviceFile mock_open_device_file;
//   MockCheckDeviceFileExists mock_check_device_file_exists;
// };

// class OpenDeviceFileTest : public ::testing::Test {
//  protected:
// };

class HandleDeviceFileTest : public ::testing::Test {
 protected:
  OsAbstractionLayer::MockOsAbstractionLayer os_abstraction_layer_{};
};

#endif  // FIXTURES_H
