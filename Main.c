/*******************************************************************************
 * Function prototypes
*******************************************************************************/
void admin_menu(void);
void user_menu(void);
nt task_admin_selector(/* not sure what to put here*/);
int task_user_selector(/* not sure what to put here*/);

/*******************************************************************************
 * Author: Owen
 * Main
*******************************************************************************/
int main(void)
{
	
	int close = 0; /* for the task selectors. */
	
	/*if admin log in. */
	do
	{
	admin_menu();
	/*  something = task_admin_selector ()*/
	}
	while(close < 1); /* inside the main somewhere to close the program. */
	
	/* if client log in. */
	do
	{
	user_menu();
	/* something = task_user_selector ()*/
	}
	while(close < 1); /* inside the main somewhere to close the program. */
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
	printf("\n"
		   "1. Add User\n"
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
int task_admin_selector(/* not sure what to put here*/)
{
	/* input */
	i = 0;
	/* Scans input from the user and directs the user to the right function.*/
	scanf("%d", &i);
	
	switch (i)
	{ /* Comment out get each case to test each function works. */
		case 1: 
			add_user(account_t* account);
			break;
		case 2: 
			delete_user(account_t* account);
			break;
		case 3: 
			edit_login(account_t* account);
			break;
		case 4: 
			view_user_log(const account_t* account);
			break;
		case 5: 
			view_user_info(const account_t* account);
			break;
		case 6; 
			/*log off function */
			break;
		case 7: 
			*close = 1; /* exit program */
			break;
	}
	/* checks the users input to the switch cases */
	if (i <= 0 || i > 7)
        {
            printf("\n"
				   "Invalid choice.\n");
        }
     return /*something */;
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
int task_user_selector(/* not sure what to put here. */)
{
	/* Input */
	i = 0;
	/* Scans input from the user and directs the user to the right function.*/
	scanf("%d", &i);
	
	switch (i)
	{ /* Comment out get each case to test each function works. */
		case 1: 
			/* create an account function */
			break;
		case 2: 
			cash_deposit(account_t* account);
			break;
		case 3: 
			cash_withdraw(account_t* account);
			break;
		case 4: 
			transfer(account_t* account);
			break;
		case 5: 
			/* View balance function*/
			break;
		case 6: 
			/*View perssonal info function*/
			break;
		case 7; 
			/* whatever log out function */
			break;
		case 8: 
			*close = 1; /* exit program */
			break;
	}
	/* checks the users input to the switch cases */
	if (i <= 0 || i > 8)
        {
            printf("\n"
				   "Invalid choice.\n");
        }
     return /*something not sure tho. */;
}