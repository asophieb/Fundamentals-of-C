#define TRUE 1
#define FALSE 0

#include <stdio.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedList.h"
#endif

int is_valid_DOB(int day, int month, int year);
int is_valid_name(char* name_p);
int is_valid_phone(char* phone_p);
int is_valid_password(char* password_p);
int is_valid_username(node_t* head, char* username);
int is_valid_email(char* email);