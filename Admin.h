#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedList.h"
#endif

#ifndef VALIDATE_H
#define VALIDATE_H
#include "Validate.h"
#endif

void delete_user(node_t* head);
void edit_user(node_t* node, user_t data_type, char* type);
void change_password(node_t* head, node_t* node);
void edit_info_menu(node_t* head);
void view_user_info(node_t* head);