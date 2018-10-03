/*********************************
    Bidirectional Linked List
*********************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedList.h"
#endif 

#ifndef ADD_USER_H
#define ADD_USER_H
#include "AddUser.h"
#endif 

node_t* create_head(const user_t new_user)
{
    node_t* head=NULL;

    head = (node_t*) malloc(sizeof(node_t));

    if(head==NULL)
    {
        return NULL;
    }

    head->user=new_user;
    head->next=NULL;
    head->previous=NULL;

    return head;
}

/* inserts node at the end */
node_t* insert_node (node_t* head, user_t new_user)
{
    node_t* current = head;

    while(current->next!=NULL)
    {
        current=current->next;
    }

    current->next=(node_t*) malloc(sizeof(node_t));

    node_t* new_node=current->next;

    if(new_node==NULL)
    {
        return NULL;
    }

    new_node->user=new_user;
    new_node->next=NULL;
    new_node->previous=current;


    return new_node;
}

node_t* remove_head (node_t* current_head)
{
    node_t* new_head = current_head->next;

    new_head->previous = NULL;

    free(current_head);

    current_head=NULL;

    return new_head;
}

void remove_tail (node_t* current_tail)
{
    node_t* new_tail = current_tail->previous;

    new_tail->next = NULL;

    free(current_tail);
    current_tail=NULL;
}

/* removes nodes at the specified address */
node_t* remove_node (node_t* current_head, node_t* to_be_deleted)
{
    node_t* new_head;

    if(to_be_deleted->previous==NULL)
    {
        new_head=remove_head(to_be_deleted);
        return new_head;
    }

    else if (to_be_deleted->next==NULL)
        remove_tail(to_be_deleted);

    else
    {
        node_t* before =  to_be_deleted->previous;
        node_t* after = to_be_deleted->next;

        before->next=after;
        after->previous=before;

        printf("middle\n");


        /* Free the deleted node */
        free(to_be_deleted);

        to_be_deleted=NULL;

    }

    return current_head;
}


/* returns the address of the node*/
node_t* search_data (node_t* head, char* search_username)
{
    node_t* current=head;

    goto CHECK; /* checks the head */

    while(current->next!=NULL)
    {
        current=current->next;

        CHECK:
        if(strcmp(current->user.login.username, search_username) == 0)
            return current;
    }

    return NULL;
}

/* print struct */
void print_struct (user_t user)
{
    printf("Username: %s\n", user.login.username); 
    printf("First name: %s\n", user.first_name);
    printf("Last name: %s\n", user.last_name);
    printf("DOB: %02d/%02d/%04d\n", user.DOB.day, user.DOB.month, user.DOB.year);
    printf("Phone: %s\n", user.phone);
    printf("Email: %s\n", user.email);
    printf("Address: %s\n", user.address);
}

/* print all the nodes in the list */
void print_all_nodes (node_t* head)
{
    node_t* current=head;

    goto PRINT;

    while(current->next!=NULL)
    {
        current=current->next;

        PRINT:
        print_struct(current->user);

    }

}

/* print a specific node */
void print_node (node_t* to_be_printed)
{
    print_struct(to_be_printed->user);
}


void save_node(FILE* fp, node_t* node)
{
    fprintf(fp,"%s\n", node->user.login.username);
    fprintf(fp,"%s\n", node->user.login.password);
    fprintf(fp, "%s\n", node->user.first_name);
    fprintf(fp,"%s\n", node->user.last_name);

    fprintf(fp, "%02d%02d%04d\n", node->user.DOB.day,
                                  node->user.DOB.month,
                                  node->user.DOB.year);

    fprintf(fp, "%s\n", node->user.phone);
    fprintf(fp,"%s\n",node->user.address);
    fprintf(fp, "%s\n", node->user.email);
    fprintf(fp, "%.2f\n", node->user.balance);
}


void save_file(node_t* head)
{
    FILE *fp;

    fp = fopen (DATABASE, "w");

    if(fp==NULL)
        printf("Read Error!\n");

    else
    {
        node_t* current=head;

        goto SAVE;

        while(current->next!=NULL)
        {
            current=current->next;

            SAVE:
            save_node(fp, current);

        }
     }

    fclose(fp);
}

/* returns the head of the linked list */
node_t* load_file (int* total_users)
{
    FILE *fp;

    fp = fopen (DATABASE, "r");

    user_t user;

    node_t* head=NULL;

    head=(node_t*) malloc(sizeof(node_t));

    if(fp==NULL)
        printf("Read Error!\n");

    else
    {

        *total_users=0;

        while(fgetc(fp)!=EOF)
        {
            fseek(fp,-1,SEEK_CUR); /* moves cursor 1 character behind */

            fscanf(fp,"%[^\n]\n", user.login.username);
            fscanf(fp,"%[^\n]\n", user.login.password);
            fscanf(fp, "%[^\n]\n", user.first_name);
            fscanf(fp,"%[^\n]\n", user.last_name);

            fscanf(fp, "%2d%2d%4d\n", &user.DOB.day,
                                      &user.DOB.month,
                                      &user.DOB.year);

            fscanf(fp, "%[^\n]\n", user.phone);
            fscanf(fp,"%[^\n]\n",user.address);
            fscanf(fp, "%[^\n]\n", user.email);
            fscanf(fp, "%f\n", &user.balance);

            if(*(total_users)==0)
                head=create_head(user);

            else
                insert_node(head, user);


            ++*(total_users);
        }
    }

    fclose(fp);

    return head;
}


