/* Compile note - gcc -Wall -Werror -ansi -c 'filename'.c
gcc -Wall -Werror 'filename'.o 'otherfile'.o 'main'.o -o Main

git git add . --> git commit -m "comment" --> git push origin master  as, 1!

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define RED      "\x1B[31m"
#define GREEN    "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE     "\x1B[34m"
#define PURPLE   "\x1B[35m"
#define CYAN     "\x1B[36m"
#define WHITE    "\x1B[37m"
#define RESET    "\x1B[0m"

#include "LinkedList.h"
#include "AddUser.h"
#include "Login.h"
#include "User.h"
#include "Admin.h"

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void admin_menu(void);
void user_menu(void);
int task_admin_selector(int total_users, node_t* head);
int task_user_selector(int total_users, node_t* head, node_t* node);

/*******************************************************************************
 * Author: Sophie, Owen
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
	head = load_users(&total_users);
	system("clear");

	/* login process, loops each time there's a log out, breaks on exit code */
	while(1)
	{
		node = login(head);

		if(node == NULL)
		{
			if(admin_password() != 0)
			{
				if(task_admin_selector(total_users, head) == 1)
				{
					system("clear");
					break;
				}
			}
		}
		else
		{
			if(user_password(node) != 0)
			{
				if(task_user_selector(total_users, head, node) == 1)
				{
					system("clear");
					break;
				}
			}
		}
	}
	return 0;
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
	printf(GREEN"\n\n\t Welcome to Administration Controls.\n\n"RESET);
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
 * Author: Sophie
 * This function switches between tasks for the admin side of the program.
 * inputs:
 * - total count of users
 * - head of the user list
 * outputs:
 * - 1 for program exit, 0 for log out
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
				save_users(head);
				break;
			case 2: 
				delete_user(head);
				save_users(head);
				break;
			case 3: 
				edit_info_menu(head);
				save_users(head);
				break;
			case 4: 
				/* TODO: View transaction logs */
				break;
			case 5: 
				view_user_info(head);
				break;
			case 6:
				save_users(head);
				return 0;
			case 7: 
				save_users(head);
				return 1;
			default:
			printf(RED"Invalid choice.\n"RESET);
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
		   "6. Change Password\n"
		   "7. Log Off\n"
		   "8. Exit Program\n"
		   "Enter choice (Between 1-8)>\n");
}

/*******************************************************************************
 * Author: Sophie, Owen
 * This function switches between tasks for the user side of the program.
 * inputs:
 * - none
 * outputs:
 * - 1 for program exit, 0 for log out
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
				deposit(node);
				break;
			case 2: 
				withdraw(node);
				break;
			case 3: 
				transfer(head, node);
				break;
			case 4: 
				system("clear");
				printf("-------------------------------------\n"	
					   "Your balance is currently $%.2lf\n", node->user.balance);
				printf("-------------------------------------\n");
				break;
			case 5: 
				print_user(node->user);
				break;
			case 6:
				change_password(head, node);
				break;
			case 7:
				save_users(head);
				return 0;	
			case 8: 
				save_users(head);
				return 1;
			default:
				printf("Invalid choice.\n");
		}
	}

     return 0;
}
