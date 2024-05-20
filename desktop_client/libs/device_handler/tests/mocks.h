#ifndef MOCKS_H
#define MOCKS_H

#include <device_handler/os_abstraction_layer.h>
#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include <functional>
#include <string>

namespace OsAbstractionLayer {

class MockOsAbstractionLayer : public OsAbstractionLayer {
 public:
  MOCK_METHOD(bool, CheckDeviceFileExists, (const std::string& device_file_path), (const));
  MOCK_METHOD(int, OpenDeviceFile, (const std::string& device_file_path), (const));
  MOCK_METHOD(int, CloseDeviceFile, (int file_descriptor), (const));
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
}  // namespace OsAbstractionLayer

#endif  // MOCKS_H
