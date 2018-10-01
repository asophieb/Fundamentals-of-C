#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void Password(char user[]);

int main(void)
{
	char user[10];
	
	printf("\n\t\t\t Welcome to Bank\n\n");
	printf("\t Username:");
	scanf("%s",user);
	Password(user);
	return (0);
}

void Password(char user[])
{
	char pass[10];
	int fin = 0;
	int exit = 1;

	if (user[0] == 'a')
	{
		printf("\t Welcome Administrator\n");
	}
	else
	{
		printf("\t Welcome User\n");
	}
	printf("\t Password:");
	scanf("%s",pass);
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
				scanf("%s",pass);
			}
			else
			{
				fin = 1;
				if (user[0] == 'a')
				{
					printf("\n\t Welcome to Administion Controls\n");
					/*Function for admin menu*/
				}
				else
				{
					printf("\n\t Welcome %s to your Account\n",user);
					/*Function for user menu*/
				}
			}
		}	
		else
		{
			printf("\n\t Sorry you are locked out.\n");
			fin = 1;
		}
	}		
}