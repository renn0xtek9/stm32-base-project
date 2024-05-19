#include <device_handler/device_handler.h>
#include <fcntl.h>
#include <unistd.h>

#include <chrono>
#include <iostream>
#include <thread>

DeviceHandler::DeviceHandler(const OsAbstractionLayer::OsAbstractionLayer& os_layer) : os_layer_(os_layer) {
}

bool DeviceHandler::HandleDevice(const std::string device_file_path) {
  if (!os_layer_.CheckDeviceFileExists(device_file_path)) {
    std::cerr << "Device file does not exist" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    return true;
  }

  int file_descriptor = os_layer_.OpenDeviceFile(device_file_path);
  if (file_descriptor < 0) {
    return false;
  }

  // Do something with the device
  // publish_to_device("Hello device");

  os_layer_.CloseDeviceFile(file_descriptor);
  return false;
}
