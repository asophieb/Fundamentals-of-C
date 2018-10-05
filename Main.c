/* Compile note - gcc -Wall -Werror -ansi -c 'filename'.c
gcc -Wall -Werror 'filename'.o 'otherfile'.o 'main'.o -o Main

git git add . --> git commit -m "comment" --> git push origin master  as, 1!

*/

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

#ifndef LOGIN_H
#define LOGIN_H
#include "Login.h"
#endif

#ifndef USER_H
#define USER_H
#include "User.h"
#endif

#ifndef ADMIN_H
#define ADMIN_H
#include "Admin.h"
#endif

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void admin_menu(void);
void user_menu(void);
int task_admin_selector(int total_users, node_t* head);
int task_user_selector(int total_users, node_t* head, node_t* node);

/*******************************************************************************
 * Structures
*******************************************************************************/

/*******************************************************************************
 * Author: Owen, Sophie
 * Main
*******************************************************************************/
int main(void)
{
	#ifdef DEBUG
		printf("help\n");
	#endif

	node_t* head = NULL;
	node_t* node;
	head = (node_t*) malloc(sizeof(node_t));

	int total_users = 0;
	load_file(&total_users);
	system("clear");

	/* int close = 0; for the task selectors. */
	while(1)
	{
		/*if admin log in. */


		if(Username(&total_users, head) == NULL)
		{

			if(task_admin_selector(total_users, head) == 2)
			{
				break;
			}

		}
		else
		{
			node = Username(&total_users, head);
			if(task_user_selector(total_users, head, node) == 2)
			{
				break;
			}
		}

	}
	
	save_file(head);

	/*  something = task_admin_selector ()*/
	
	 /* while(close < 1); inside the main somewhere to close the program. */
	
	/* if client log in. */
	
	
	/* something = task_user_selector ()*/
	
	/* while(close < 1);  inside the main somewhere to close the program. */
	return 1;
}
/*******************************************************************************
 * Author: Owen
 * This function prints the admin menu with instructions on how to use
 * this program.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void admin_menu(void)
{
	printf("\n\n\t Welcome to Administration Controls.\n\n");
	printf("1. Add User\n"
		   "2. Delete User\n"
		   "3. Edit User Information\n"
		   "4. View User Log\n"
		   "5. View User Info\n"
		   "6. Log Off\n"
		   "7. Exit Program\n"
		   "Enter choice (Between 1-7)>\n");
}

/*******************************************************************************
 * Author: Owen, Sophie
 * This function switches between tasks for the admin side of the program.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
int task_admin_selector(int total_users, node_t* head)
{
	
	while(1)
	{
		admin_menu();
		/* input */
		int i = 0;
		/* Scans input from the user and directs the user to the right function.*/
		scanf("%d", &i);
		while(getchar()!='\n');
		system("clear");

		switch (i)
		{ /* Comment out get each case to test each function works. */
			case 1: 
				head = add_user(head, &total_users);
				break;
			case 2: 
				delete_user(head);
				break;
			case 3: 
				edit_info(head);
				break;
			case 4: 
				
				break;
			case 5: 
				view_user_info(head);
				break;
			case 6:
				return 0;
			case 7: 
				return 2;
			default:
			printf("Invalid choice.\n");
		}
	}
	return 0;
}

/*******************************************************************************
 * Author: Owen
 * This function prints the user menu with all instructions on how to use
 * this program.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
void user_menu(void)
{
	printf("\n"
		   "1. Cash Deposit\n"
		   "2. Cash Withdraw\n"
		   "3. Funds Transfer\n"
		   "4. View Balance\n"
		   "5. View Personal Info\n"
		   "6. Log Off\n"
		   "7. Exit Program\n"
		   "Enter choice (Between 1-7)>\n");
}
/*******************************************************************************
 * Author: Owen, Sophie
 * This function switches between tasks for the user side of the program.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
int task_user_selector(int total_users, node_t* head, node_t* node)
{	
	while(1)
	{
		user_menu();
			/* Input */
		int i = 0;
		/* Scans input from the user and directs the user to the right function.*/
		scanf("%d", &i);
		while(getchar()!='\n');
		system("clear");
		
		switch (i)
		{ /* Comment out get each case to test each function works. */
			case 1: 

				break;
			case 2: 
				
				break;
			case 3: 
				
				break;
			case 4: 
				system("clear");

				printf("Your balance is currently %lf", node->user.balance);
				break;
			case 5: 
				print_struct(node->user);
				break;
			case 6:
				return 0;
			case 7: 
				return 2;
			default:
				printf("Invalid choice.\n");
		}
	}

     return 0;
}