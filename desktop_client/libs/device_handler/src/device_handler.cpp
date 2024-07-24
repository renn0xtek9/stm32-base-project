// Copyright 2024 <Maxime Haselbauer>
#include <device_handler/device_handler.h>
#include <fcntl.h>
#include <unistd.h>

#include <chrono>
#include <iostream>
#include <thread>  // LCOV_EXCL_LINE

DeviceHandler::DeviceHandler(const OsAbstractionLayer::OsAbstractionLayerInterface& os_layer) : os_layer_(os_layer) {
}

bool DeviceHandler::HandleDevice(const std::string device_file_path) {
  if (!os_layer_.CheckDeviceFileExists(device_file_path)) {
    std::cout << "Device file does not exist. (Will retry)" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return true;
  }

  int file_descriptor = os_layer_.OpenDeviceFile(device_file_path);
  if (file_descriptor < 0) {
    std::cerr << "Could not open device file properly. Exiting" << std::endl;
    return false;
  }

  PublishToDevice(CommunicationMessage());
  os_layer_.CloseDeviceFile(file_descriptor);
  return false;
}

void DeviceHandler::PublishToDevice(const CommunicationMessage&) {
  std::cout << "Publishing a message to the device:" << std::endl;
}
