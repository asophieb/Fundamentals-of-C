#ifndef ENCRYPT_H
#define ENCRYPT_H

#include "LinkedList.h"

char* XOR(char* string, char key);
user_t encrypt(user_t user);
user_t decrypt(user_t user);

#endif
