#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include "LinkedList.h"
#endif

/*******************************************************************************
 * Author: Sophie
 * This function prompts a user to enter a integer amount to be deposited into
 * the balance.
 * inputs:
 * - user
 * outputs:
 * - none
*******************************************************************************/
void deposit(node_t* node)
{
	double amount; 
	system("clear");
	printf("Your account balance is now $%.2lf\n", node->user.balance);
	printf("Please enter the amount that you wish to deposit > ");
	scanf("%lf", &amount);
	system("clear");
	
	if(amount > 0)
	{
		node->user.balance = node->user.balance + amount;
		printf("Your transaction has been processed...\n");
		printf("Your account balance is now $%.2lf\n", node->user.balance);
		printf("--------------------------------------\n");
	}
	
	else
	{
		printf("Unable to process transaction.\n");
	}

}

/*******************************************************************************
 * Author: Sophie 
 * This function prompts the user to enter an integer amount to be widthdrawn
 * from the balance.
 * inputs:
 * - user
 * outputs:
 * - none
*******************************************************************************/
void withdraw(node_t* node)
{
	double amount; 
	
	system("clear");
	printf("Your account balance is $%.2lf\n", node->user.balance);
	printf("Please enter the amount that you wish to withdraw > ");
	scanf("%lf", &amount);
	system("clear");
	
	if(amount <= node->user.balance && amount > 0)
	{
		node->user.balance = node->user.balance - amount;
		printf("Your transaction has been processed...\n");
		printf("Your account balance is now $%.2lf\n", node->user.balance);
		printf("--------------------------------------\n");
	}

	else if(amount >= node->user.balance)
		{
			printf("Unable to process transaction.\n");
			printf("Please ensure you have sufficent funds.\n");
		}
	
	else
	{
		printf("Unable to process transaction.\n");
	}

}


/*******************************************************************************
 * Author: Sophie 
 * This function prompts the user to enter an integer amount to be transferred
 * from the balance to another balance.
 * inputs:
 * - user
 * outputs:
 * - none
*******************************************************************************/
void transfer(node_t* head, node_t* node)
{
	double amount;
	char ID[MAX_USERNAME_LEN];
	node_t* transfer_node;

	printf("Please enter the User ID to transfer to > ");
	scanf("%s", ID);
	transfer_node = search_data(head, ID);

	if(transfer_node != NULL)
	{
		printf("Please enter the amount to be transferred > ");
		scanf("%lf", &amount);
		if(amount <= node->user.balance && amount > 0)
		{	
			transfer_node->user.balance = transfer_node->user.balance + amount;
			node->user.balance = node->user.balance - amount;
			printf("Your transaction has been processed...\n"
				   "Your account balance is now $%.2lf\n", node->user.balance);
			printf("--------------------------------------\n");

		}
		else if(amount >= node->user.balance)
		{
			printf("Unable to process transaction.\n");
			printf("Please ensure you have sufficent funds.\n");
		}
		else
		{
			printf("Unable to process transaction.\n");
		}
	}
	else 
	{
		printf("This user does not exist.\n");
	}
}



