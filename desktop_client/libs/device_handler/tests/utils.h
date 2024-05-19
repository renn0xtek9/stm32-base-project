#include <gmock/gmock.h>
#include <gtest/gtest.h>
class MockFileOperations {
 public:
  MOCK_METHOD(int, open, (const char* pathname, int flags), ());
};

class MockOpenDeviceFile {
 public:
  MOCK_METHOD(int,
              OpenDeviceFile,
              (const std::string& device_file_path, std::function<int(const char*, int)> open_func),
              ());
};

class MockCheckDeviceFileExists {
 public:
  MOCK_METHOD(bool, CheckDeviceFileExists, (const std::string& device_file_path), ());
};

class OpenDeviceFileTest : public ::testing::Test {
 protected:
  MockFileOperations mock_file_operations;
};

class HandleDeviceFileTest : public ::testing::Test {
 protected:
  MockFileOperations mock_file_operations;
  MockOpenDeviceFile mock_open_device_file;
  MockCheckDeviceFileExists mock_check_device_file_exists;
};
