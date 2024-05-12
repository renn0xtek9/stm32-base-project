#include "device_handler.h"

#include <string>
#include <vector>
bool CheckDeviceFileExists(const std::string& device_file_path) {
  if (access(device_file_path.c_str(), F_OK) == 0) {
    return true;
  } else {
    return false;
  }
}
