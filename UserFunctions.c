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
 * - balance amount, user ID
 * outputs:
 * - new balance
*******************************************************************************/
void deposit(user_t user)
{
	while(0)
	{
		system("clear");
		printf("\t Please enter the amount that you wish to deposit > ");
		scanf("%d\n", amount);
		if(amount > 0)
		{
			user.balance = user.balance + amount;
			system("clear");
			printf("\tYour transaction has been processed...")
			printf("\tThe account balance is now %d", user.balance)
			return 1;
		}
		
		else
		{
			printf("Invalid choice.\n")
		}
	}

}

/*******************************************************************************
 * Author: Sophie 
 * This function prompts the user to enter an integer amount to be widthdrawn
 * from the balance.
 * inputs:
 * - balance amount, user ID
 * outputs:
 * - new balance
*******************************************************************************/
void withdraw(user_t user)
{
	return 1;
}
/*******************************************************************************
 * Author: Sophie 
 * This function prompts the user to enter an integer amount to be transferred
 * from the balance to another balance.
 * inputs:
 * - balance amount, user ID
 * outputs:
 * - new balance
*******************************************************************************/
void transfer(user_t user)
{
	return 1;
}
