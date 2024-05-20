// Copyright 2024 <Maxime Haselbauer>
#include <messages/communication_message.h>
#include <serializer/serializer.h>

#include <string>
namespace serializer {

std::string SerializeToString(const CommunicationMessage& message) {
  std::string serialized_message{};
  serialized_message.append(message.message, message.message_length);
  serialized_message.append(" ");
  serialized_message.append(std::to_string(message.value));
  return serialized_message;
}

}  // namespace serializer
