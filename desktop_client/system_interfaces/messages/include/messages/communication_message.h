// Copyright 2024 <Maxime Haselbauer>
#ifndef MESSAGES_COMMUNICATION_MESSAGE_H
#define MESSAGES_COMMUNICATION_MESSAGE_H

const unsigned short MAXIMUM_MESSAGE_LENGTH = 64;

struct CommunicationMessage {
  char message[MAXIMUM_MESSAGE_LENGTH];
  unsigned short message_length;
  int value;
};

#endif  // MESSAGES_COMMUNICATION_MESSAGE_H
