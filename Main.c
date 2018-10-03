/* Compile note - gcc -Wall -Werror -ansi -c 'filename'.c
gcc -Wall -Werror 'filename'.o 'otherfile'.o 'main'.o -o Main
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

#ifndef USER_FUNCTIONS_H
#define USER_FUNCTIONS_H
#include "UserFunctions.h"
#endif

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void admin_menu(void);
void user_menu(void);
int task_admin_selector(node_t* head);
int task_user_selector(node_t* head);

/*******************************************************************************
 * Structures
*******************************************************************************/

/*******************************************************************************
 * Author: Owen
 * Main
*******************************************************************************/
int main(void)
{
	node_t* head = NULL;
	head = (node_t*) malloc(sizeof(node_t));

	char username[10];
	/* int close = 0; for the task selectors. */
	while(1)
	{
		/*if admin log in. */
		system("clear");
		printf("\n\t\t\t Welcome to Bank\n\n");
		printf("\t Username:");
		scanf("%s", username);
		while(getchar()!='\n');
		system("clear");

		if(strcmp(username, "admin"))
		{
			task_admin_selector(head);
		}
		else
		{
			task_user_selector(head);
		}

	}
	



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
	printf("1. Add User\n"
		   "2. Delete User\n"
		   "3. Edit Username/Password\n"
		   "4. View User Log\n"
		   "5. View User Info\n"
		   "6. Log Off\n"
		   "7. Exit Program\n"
		   "Enter choice (Between 1-7)>\n");
}

/*******************************************************************************
 * Author: Owen
 * This function switches between tasks for the admin side of the program.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
int task_admin_selector(node_t* head)
{
	
	while(0)
	{
		admin_menu();
		/* input */
		int i = 0, total_users = 0;
		/* Scans input from the user and directs the user to the right function.*/
		scanf("%d", &i);
		while(getchar()!='\n');
		system("clear");

		switch (i)
		{ /* Comment out get each case to test each function works. */
			case 1: 
				head = add_user(head, &total_users);
				print_node(head);
				break;
			case 2: 
				
				break;
			case 3: 
				
				break;
			case 4: 
				
				break;
			case 5: 
				
				break;
			case 6:
				return 1;
				break;
			case 7: 
				/* *close = 1;  exit program */
				return 0;
			default:
			printf("Invalid choice.\n");
		}
	}
	return 1;
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
		   "1. Create New Account\n"
		   "2. Cash Deposit\n"
		   "3. Cash Withdraw\n"
		   "4. Funds Transfer\n"
		   "5. View Balance\n"
		   "6. View Personal Info\n"
		   "7. Log Off\n"
		   "8. Exit Program\n"
		   "Enter choice (Between 1-8)>\n");
}
/*******************************************************************************
 * Author: Owen
 * This function switches between tasks for the user side of the program.
 * inputs:
 * - none
 * outputs:
 * - none
*******************************************************************************/
int task_user_selector(node_t* head)
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
				/* create an account function */
				break;
			case 2: 

				break;
			case 3: 
				
				break;
			case 4: 
				
				break;
			case 5: 
				/* View balance function*/
				break;
			case 6: 
				
				/*View perssonal info function*/
				break;
			case 7:
				/* whatever log out function */
				return 0;
				break;
			case 8: 
				/*  *close = 1; exit program */
				return 1;
				break;
			default:
				printf("Invalid choice.\n");
		}
	}

     return 0;
}