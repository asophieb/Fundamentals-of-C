/*********************************
    Bidirectional Linked List
*********************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "AddUser.h"
#include "LinkedList.h"

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

