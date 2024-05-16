/*! \file device_handler.h
\brief Handle STM32 device
*/
#include <unistd.h>

#include <iostream>

/*! \fn void CheckDeviceFileExists()
 * \brief This checks whether the device file has been created by the Linux kernel
 * \param device_file_path the path device file to check
 * \return true if the device file exists, false otherwise
 */
bool CheckDeviceFileExists(const std::string& device_file_path);
