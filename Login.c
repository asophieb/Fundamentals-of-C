#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedList.h"
#endif

#define DATABASE "user.txt"

char Username(char user[]);
int Password(char user[]);

int main(void)
{
	char user[10];

	/*FILE* fp;
	fp = fopen(DATABASE, "r");
	fclose(DATABASE);*/

	
	printf("\n\t\t\t Welcome to Bank\n\n");
	printf("\t Username:");
	scanf("%s",user);
	User(user);
	Password(user);
	return 0;
}

char Username(char user[])
{
	if (user[0] == 'A' && user[1] == 'd' && user[2] == 'm' &&
		user[3] == '1' && user[4] == 'n') /*Hard code admin*/
	{
		printf("\t Welcome Administrator\n");
		return (user[0]);
	}
	else
	{
		printf("\t Welcome User\n");
		return (user[0]);
	}
}

int Password(char user[])
{
	char pass[10];
	int fin = 0;
	int exit = 1;

	printf("\t Password:");
	system("stty -echo"); /* Turns off character display */
	scanf("%s",pass);
	system("stty echo"); /* Turn echoing of characters back on */

	while(!fin)
	{
		if (exit < 5)
		{
			if(pass[0] != user[0])
			{
				exit++;
				printf("\n\t *Wrong Password*\n\n");
				printf("\t Attempt %d\n",exit);
				
				printf("\t Re-Enter Password:");
				system("stty -echo"); /* Turns off character display */
				scanf("%s",pass);
				system("stty echo"); /* Turn echoing of characters back on */
			}
			else
			{
				fin = 1;
				if (user[0] == 'a')
				{
					printf("\n\t Welcome to Administion Controls\n");
					/*Function for admin menu*/
					return 1;
				}
				else
				{
					printf("\n\t Welcome %s to your Account\n",user);
					/*Function for user menu*/
					return 2;
				}
			}
		}	
		else
		{
			printf("\n\t Sorry you are locked out.\n");
			fin = 1;	
		}
	}
	return 0;		
}