#include <device_handler/device_handler.h>
#include <fcntl.h>
#include <unistd.h>

#include <cstring>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

bool CheckDeviceFileExists(const std::string& device_file_path) {
  if (access(device_file_path.c_str(), F_OK) == 0) {
    return true;
  } else {
    return false;
  }
}

int OpenDeviceFile(const std::string& device_file_path, std::function<int(const char*, int)> open_func) {
  int file_descriptor = open_func(device_file_path.c_str(), O_RDWR | O_NOCTTY | O_SYNC);
  if (file_descriptor < 0) {
    std::cerr << "Error opening device file: " << strerror(errno) << std::endl;
    return -1;
  }
  return file_descriptor;
}
