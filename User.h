#ifndef USER_H
#define USER_H

#define DATABASE "user.txt"

void deposit(node_t* node);
void withdraw(node_t* node);
void transfer(node_t* head, node_t* node);
void save_user(FILE* fp, user_t user);
void save_users(node_t* head);
node_t* load_users(int* total_users);

#endif
