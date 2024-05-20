#ifndef MESSAGES_COMMUNICATION_MESSAGE_H
#define MESSAGES_COMMUNICATION_MESSAGE_H

namespace messages {

const unsigned short MAXIMUM_MESSAGE_LENGTH = 64;

struct CommunicationMessage {
  char message[MAXIMUM_MESSAGE_LENGTH];
  unsigned short message_length;
  int value;
};

}  // namespace messages

#endif  // MESSAGES_COMMUNICATION_MESSAGE_H
