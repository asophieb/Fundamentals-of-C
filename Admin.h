#ifndef ADMIN_H
#define ADMIN_H

#include "LinkedList.h"
#include "Validate.h"

void delete_user(node_t* head);
void edit_user(node_t* node, user_t data_type, char* type);
void change_password(node_t* head, node_t* node);
void edit_info_menu(node_t* head);
void view_user_info(node_t* head);

#endif
