/* Compile note - gcc -Wall -Werror -ansi -c 'filename'.c
gcc -Wall -Werror 'filename'.o 'otherfile'.o 'main'.o -o Main
*/

#define MAX_USERS 20

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "AddUser.h"

/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void admin_menu(void);
void user_menu(void);
int task_admin_selector(void);
int task_user_selector(void);

/*******************************************************************************
 * Structures
*******************************************************************************/

/*******************************************************************************
 * Author: Owen
 * Main
*******************************************************************************/
int main(void)
{
	char username[20];
	/* int close = 0; for the task selectors. */
	
	/*if admin log in. */
	printf("Enter Username > ");
	scanf("%s", username);

	if(strcmp(username, "admin") == 0)
	{
		task_admin_selector();
	}
	else
	{
		task_user_selector();
	}


	/*  something = task_admin_selector ()*/
	
	 /* while(close < 1); inside the main somewhere to close the program. */
	
	/* if client log in. */
	
	
	/* something = task_user_selector ()*/
	
	/* while(close < 1);  inside the main somewhere to close the program. */
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
int task_admin_selector(void)
{
	
	while(1)
	{
		admin_menu();
		/* input */
		int i = 0, total_users = 0;
		/* Scans input from the user and directs the user to the right function.*/
		scanf("%d", &i);

		switch (i)
		{ /* Comment out get each case to test each function works. */
			case 1: 
				add_user(node_t* head, int* total_users);
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
int task_user_selector(void)
{	
	while(1)
	{
		user_menu();
			/* Input */
		int i = 0;
		/* Scans input from the user and directs the user to the right function.*/
		scanf("%d", &i);
		
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
				break;
			case 8: 
				/*  *close = 1; exit program */
				return 0;
				break;
			default:
				printf("Invalid choice.\n");
		}
	}

     return 0;
}