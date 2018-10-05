#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_FIRSTNAME_LEN 30
#define MAX_LASTNAME_LEN 256
#define MAX_EMAIL_LEN 256
#define MAX_ADDRESS_LEN 256
#define MAX_USERNAME_LEN 10
#define MAX_PHONE_LEN 10

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedList.h"
#endif

#ifndef ADD_USER_H
#define ADD_USER_H
#include "AddUser.h"
#endif

#ifndef VALIDATE_H
#define VALIDATE_H
#include "Validate.h"
#endif


/*******************************************************************************
 * Author: Rohan
 * This function creates a new user and add to the linked list .
 * inputs:
 * - pointer to first node, number of users
 * outputs:
 * - ppinter to first node
*******************************************************************************/

node_t* add_user(node_t* head, int* total_users)
{
    system("clear");

    printf("Please provide the following personal information\n\n"
           "----------------------------------------------------\n");

    user_t temp_user;

    /* Get First Name */
    while(1)
    {
        printf("First Name>\n");

        scanf("%[^\n]", temp_user.first_name);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate first name */
        if(is_valid_name(temp_user.first_name)==TRUE)
        {
            break;
        }

        printf("Invalid input. Do not enter any symbol.\n");
    }

    /* Get Last Name */
    while(1)
    {
        printf("Last Name>\n");

        scanf("%[^\n]", temp_user.last_name);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate last name */
        if(is_valid_name(temp_user.last_name) == TRUE)
        {
            break;
        }

        printf("Invalid input. Do not enter any symbol\n");
    }

    /* Get DOB */
    while(1)
    {
        printf("DOB (dd/mm/yyyy)>\n");

        scanf("%d/%d/%d", &temp_user.DOB.day,
                          &temp_user.DOB.month,
                          &temp_user.DOB.year);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate DOB */
        if(is_valid_DOB( temp_user.DOB.day,
                         temp_user.DOB.month,
                         temp_user.DOB.year)==TRUE)
        {
            break;
        }

        printf("Invalid input\n");
    }


    /* Get Phone Number */
    while(1)
    {
        printf("Phone>\n");

        scanf("%s", temp_user.phone);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate phone */
        if(is_valid_phone(temp_user.phone)==TRUE)
        {
            break;
        }

        printf("Invalid input\n");
    }

    /* Get Email */
    while(1)
    {
        printf("Email>\n");

        scanf("%[^\n]", temp_user.email);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate email */
        if(is_valid_email(temp_user.email)==TRUE)
        {
            break;
        }

        printf("Invalid input\n");
    }

    /* Get Address */
    while(1)
    {
        printf("Address>\n");

        scanf("%[^\n]", temp_user.address);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate address */

        break;
        
    }

    system("clear");

    printf("Please input the Username and Password\n\n"
           "----------------------------------------\n\n");

    while(1)
    {
        printf("\tUsername: ");
        scanf("%s", temp_user.login.username);

        /* clears the input buffer */
        while (getchar()!='\n');

        if(is_valid_username(temp_user.login.username) == TRUE)
        {
            break;
        }

        printf("This username is already taken!\n");
    }

    while(1)
    {
        printf("\tPassword: ");
        scanf("%s", temp_user.login.password);

        /* clears the input buffer */
        while (getchar()!='\n');

        is_valid_password(temp_user.login.password);

        break;

        printf("Password must be 8-10 characters long!");
    }

    /* creates a new balance account with balance $0.00 */

    system("clear");

    temp_user.balance=0.00;

    printf("User %s has been created successfully!\n", temp_user.first_name);
    printf("\nAccount Details:\n\n");
    printf("\tAccount Type: Balance\n\tNet Balance: $%.2f\n", temp_user.balance);
    printf("\n\n\n\n\nPress Enter to continue...");

    if(*(total_users)==0)
        head=create_head(temp_user);

    else
        insert_node(head, temp_user);

    ++*(total_users);

    while (getchar()!='\n');

    return head;
}
