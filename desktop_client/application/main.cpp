// Copyright 2024 <Maxime Haselbauer>
#include <device_handler/device_handler.h>
#include <device_handler/os_abstraction_layer.h>

#include <iostream>
#include <memory>
#include <vector>

#include "version.hpp"

int main(int, char**) {
  OsAbstractionLayer::OsAbstractionLayer os_abstraction_layer{};

  DeviceHandler device_handler{os_abstraction_layer};
  while (device_handler.HandleDevice(micro_controller_device_file_path)) {
  }

  return 0;
}
