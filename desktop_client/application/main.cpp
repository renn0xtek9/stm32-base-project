#include <device_handler/device_handler.h>

#include <iostream>
#include <memory>
#include <vector>

#include "version.hpp"

int main(int argc, char** argv) {
  DeviceHandler device_handler;
  while (device_handler.HandleDevice(micro_controller_device_file_path)) {
  }

  return 0;
}
