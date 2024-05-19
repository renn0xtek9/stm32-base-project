/*! \file device_handler.h
\brief Handle STM32 device
*/
#include <unistd.h>

#include <functional>
#include <iostream>

/*! \fn void CheckDeviceFileExists
 * \brief This checks whether the device file has been created by the Linux kernel
 * \param device_file_path the path device file to check
 * \return true if the device file exists, false otherwise
 */
bool CheckDeviceFileExists(const std::string& device_file_path);

/*! \fn int OpenDeviceFile
 *\brief This Open a device file
 *\param device_file_path the path device file to check
 *\return file_descriptor_id. -1 if the file could not be opened
 */
int OpenDeviceFile(const std::string& device_file_path, std::function<int(const char*, int)> open_func);
