#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedList.h"
#endif

#ifndef LOGIN_H
#define LOGIN_H
#include "Login.h"
#endif

#define MAX_USER 10
#define MAX_PASS 10
#define DATABASE "user.txt"
/*colours*/
#define RED   	 "\x1B[31m"
#define GREEN    "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE     "\x1B[34m"
#define PURPLE   "\x1B[35m"
#define CYAN     "\x1B[36m"
#define WHITE    "\x1B[37m"
#define RESET    "\x1B[0m"


node_t* Username(int* total_user, node_t* head)
{
	char user[MAX_USER];
	node_t* found_address = NULL;

	printf("\n\t\t\t Welcome to Bank\n\n");
	while(found_address == NULL)
	{
		
		printf("\t Username:");
		scanf("%s", user);

		if (strcmp(user, "admin") == 0) /*Hard code admin*/
		{
			/*Welcome Administrator*/
			return (NULL);/*return when its admin*/
		}

		else
		{
		
			found_address = search_data(head, user);

			if(found_address == NULL)
			{
				printf(RED "\n\t This Username Does Not Exist.\n\n" RESET);
			}
			else
			{
				/*Welcome User*/
				return(found_address);/*return when is user*/
			}
		}
	}	
	return 0;
}

int Password(char user[], node_t* found_address)
{
	char pass[MAX_PASS];
	int fin = 0;
	int exit = 1;
	char* saved_password;
    saved_password = found_address->user.login.password;
    /*printf("%s\n", saved_password );*/

	printf("\t Password:");
	system("stty -echo"); /* Turns off character display */
	scanf("%s",pass);
	system("stty echo"); /* Turn echoing of characters back on */

	while(!fin)
	{
		if (exit < 5)/*5 attempts to sign in*/
		{
			if(strncmp(saved_password, pass, 10) != 0)/*User password compear*/
			{
				exit++;
				printf(RED "\n\n\t *Wrong Password*\n\n" RESET);
				printf("\t Attempt %d\n",exit);
				
				printf("\t Re-Enter Password:");
				system("stty -echo"); /* Turns off character display */
				scanf("%s",pass);
				system("stty echo"); /* Turn echoing of characters back on */
			}
			else
			{
				fin = 1;/*end while look*/

				char first_name[10];
				char last_name[256];

				strcpy(first_name, found_address->user.first_name);
				strcpy(last_name, found_address->user.last_name);

				printf("\n\n\t Welcome to your Account, %s %s \n\n", 
						first_name, last_name);
				
				return 2;/*return 2 when user signed in*/
				
			}
		}	
		else
		{
			printf(RED  "\n\n\t Sorry you are locked out.\n\n" RESET);
			system("clear");
			fin = 1;	
		}
	}
	return 0;		
}

int Admin_Pass()
{
	char pass[MAX_PASS];
	int fin = 0;
	int exit = 1;
	char *Ad_Pass = "password"; /*Hard coded admin password*/
	
	printf("\t Password:");
	system("stty -echo"); /* Turns off character display */
	scanf("%s",pass);
	system("stty echo"); /* Turn echoing of characters back on */

	while(!fin)
	{
		if (exit < 5)
		{
			if(strncmp(Ad_Pass, pass, 10) != 0)/*Admin password compear*/
			{
				exit++;
				printf(RED "\n\n\t *Wrong Password*\n\n" RESET);
				printf("\t Attempt %d\n",exit);
				
				printf("\t Re-Enter Password:");
				system("stty -echo"); /* Turns off character display */
				scanf("%s",pass);
				system("stty echo"); /* Turn echoing of characters back on */
			}
			else
			{
				fin = 1;
					/*Function for admin menu*/
					return 1; /*return 1 when admin signed in*/
			}
		}	
		else
		{
			printf(RED "\n\t Sorry you are locked out.\n" RESET);
			system("clear");
			fin = 1;	
		}
	}	
	return 0;
}