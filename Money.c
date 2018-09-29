/*******************************************************************************
 * Author: Sophie
 * This function prompts a user to enter a integer amount to be deposited into
 * the balance.
 * inputs:
 * - balance amount, user ID
 * outputs:
 * - new balance
*******************************************************************************/
int cash_deposit(user_t* user)
{
	while(0)
	{

		printf("Please enter the amount that you wish to deposit\n");
		scanf("%d\n", amount);
		if(amount > 0)
		{
			user.account = user.account + amount;
			printf("The account balance is now %d", user.account)
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
int cash_withdraw(user_t* user)
{
	while(0)
	{
		printf("Please enter the amount that you wish to widthdraw\n");
		scanf("%d\n", amount);
		if(amount <= user.account)
		{
			user.account = user.account - amount;
			printf("The account balance is now %d", user.account)
			break;
		}
		
		else
		{
			printf("Invalid choice.\n")
		}
	}
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
int transfer(user_t* user)
{
	while(0)
	{
		printf("Please enter the amount that you wish to transfer\n");
		scanf("%d\n", amount);
		if(amount <= user.account)
		{
			while(0)
			{
				printf("Please enter the ID of the recipient's account")
				if()
			}

			user.account = user.account - amount;
			printf("The account balance is now %d", user.account)
			return 1;
		}
		
		else
		{
			printf("Invalid choice.\n")
		}
	}
}
