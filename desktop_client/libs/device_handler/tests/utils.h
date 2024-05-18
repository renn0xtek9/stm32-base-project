#include <gmock/gmock.h>
#include <gtest/gtest.h>
class MockFileOperations {
 public:
  MOCK_METHOD(int, open, (const char* pathname, int flags), ());
};

class OpenDeviceFileTest : public ::testing::Test {
 protected:
  MockFileOperations mock_file_operations;
};
