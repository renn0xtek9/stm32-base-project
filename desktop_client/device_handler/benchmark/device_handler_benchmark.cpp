/*! \file device_handler_benchmark.cpp
 * \brief Benchmark runtime of probe library
 */
#include <device_handler.h>

#include <chrono>
#include <iostream>
int main(int argc, char** argv) {
  auto start = std::chrono::high_resolution_clock::now();
  CheckDeviceFileExists("/dev/not_a_real_device");
  auto stop = std::chrono::high_resolution_clock::now();

  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

  std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

  return 0;
}
