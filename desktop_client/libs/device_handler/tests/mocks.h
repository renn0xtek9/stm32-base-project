#ifndef MOCKS_H
#ifndef MOCKS_H

#include <device_handler/os_abstraction_layer.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <functional>
#include <string>

class MockOsAbstractionLayer : public OsAbstractionLayer {
 public:
  MOCK_METHOD(bool, CheckDeviceFileExists, (const std::string& device_file_path), (const, override));
  MOCK_METHOD(int, OpenDeviceFile, (const std::string& device_file_path), (const, override));
  MOCK_METHOD(int, CloseDeviceFile, (int file_descriptor), (const, override));
};

// class MockFileOperations {
//  public:
//   MOCK_METHOD(int, open, (const char* pathname, int flags), ());
// };

// class MockOpenDeviceFile {
//  public:
//   MOCK_METHOD(int,
//               OpenDeviceFile,
//               (const std::string& device_file_path, std::function<int(const char*, int)> open_func),
//               ());
// };

// class MockCheckDeviceFileExists {
//  public:
//   MOCK_METHOD(bool, CheckDeviceFileExists, (const std::string& device_file_path), ());
// };

#endif  // MOCKS_H
