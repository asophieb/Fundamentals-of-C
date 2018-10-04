#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedList.h"
#endif

/*******************************************************************************
 * Author: Sophie
 * This function prompts a user to enter a user to be deleted.
 * inputs:
 * - pointer to first node
 * outputs:
 * - none
*******************************************************************************/

void delete_user(node_t* head)
{
	char choice[MAX_USERNAME_LEN];
	char* confirm;
	node_t* user;

	while(0)
	{
		system("clear");
		printf("Enter the user ID of the user to be deleted > ");
		scanf("%s", choice);
		user = search_data(head, choice);

		if(user != NULL)
		{
			system("clear");
			print_node(user);
			printf("Do you want to delete this user? y or n > ");
			scanf("%c", confirm);
			if(strcmp(confirm, "y"))
			{
				remove_node(head, user);
				break;
			}
		}

		else
		{
			printf("Please enter a valid choice.");
		}
	}

}

/*******************************************************************************
 * Author: Sophie
 * This function allows the user to edit user information.
 * inputs:
 * - user
 * outputs:
 * - none
*******************************************************************************/

int edit_info(user_t user)
{
	char placeholder[256];
	char* choice;

	while(1)
	{
		system("clear");
		printf("\n\t\t\tUser Information Editor"
		   "\n1. First Name"
		   "\n2. Last Name"
		   "\n3. Date Of Birth"
		   "\n4. Phone Number"
		   "\n5. Email Address"
		   "\n6. Home Address"
		   "\n7. Username"
		   "\n8. Password"
		   "\n9. Exit Editor"
   		   "Enter choice (Between 1-9)>\n");
		
		int i = 0;
		/* Scans input from the user and directs the user to the right function.*/
		scanf("%d", &i);
		while(getchar()!='\n');
		system("clear");
		
		switch (i)
		{ /* Comment out get each case to test each function works. */
			case 1: 
				while(0)
				{
					printf("Enter the new first name > ");
					scanf("%s", placeholder);
					system("clear");
					printf("The user's first name will change from %s to %s",
							user.first_name, placeholder);

						printf("Do you accept this change? y or n > ");
						scanf("%c", choice);
						if(strcmp(choice, "y"))
						{
							strcpy(user.first_name, placeholder);
							break;
						}
				}
				break;
			case 2: 

				break;
			case 3: 
				
				break;
			case 4: 
				
				break;

				break;
			case 6: 
				
				break;
			case 7:

				break;
			case 8: 

				break;
			case 9:
				return 1;
			default:
				printf("Invalid choice.\n");
		}
	}
}

/*******************************************************************************
 * Author: Sophie
 * This function prints either a specifc user or all users
 * inputs:
 * - pointer to first node 
 * outputs:
 * - none
*******************************************************************************/

void view_user_info(node_t* head)
{
	
	char choice[MAX_USERNAME_LEN];

	while(0)
	{
		printf("Enter the User ID of a specific user or press * to print all");
		scanf("%s", choice);

		if(strcmp(choice, "*"))
		{
			print_all_nodes(head);
			break;
		}

		else if(search_data(head, choice) != NULL)
		{
			print_node(search_data(head, choice));
			break;
		}

		else
		{
			printf("Please enter a valid choice.");
		}
	}
}