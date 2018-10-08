#include "User.h"

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
 * This function prompts the user to enter an amount to be transferred from the
 * balance to another account.
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
    transfer_node = find_node(head, ID);

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

/*******************************************************************************
 * Author: Rohan
 * This function saves the individual users.
 * inputs:
 * - pointer to the open file to save to.
 * - the user to be saved.
 * outputs:
 * - none
*******************************************************************************/
void save_user(FILE* fp, const user_t user)
{
    fprintf(fp,"%s\n", user.login.username);
    fprintf(fp,"%s\n", user.login.password);
    fprintf(fp, "%s\n", user.first_name);
    fprintf(fp,"%s\n", user.last_name);

    fprintf(fp, "%02d%02d%04d\n", user.DOB.day,
                                  user.DOB.month,
                                  user.DOB.year);

    fprintf(fp, "%s\n", user.phone);
    fprintf(fp,"%s\n",user.address);
    fprintf(fp, "%s\n", user.email);
    fprintf(fp, "%.2f\n", user.balance);
}

/*******************************************************************************
 * Author: Rohan
 * This function saves a saved linked list of users to a file.
 * inputs:
 * - pointer to the head of the list.
 * outputs:
 * - none
 *******************************************************************************/
void save_users(node_t* head)
{
    FILE *fp;
    fp = fopen (DATABASE, "w");

    if(fp == NULL)
        printf("Read Error!\n");
    else
    {
        user_t encrypted_user;

        /* Iterate through linked list*/
        node_t* current;
        for (current = head; current != NULL; current = current->next) 
        {
            encrypted_user = encrypt(current->user);
            save_user(fp, encrypted_user);
        }
     }

    fclose(fp);
}

/*******************************************************************************
 * Author: Rohan
 * This function loads a saved users file to a linked list.
 * inputs:
 * - pointer to the number of users.
 * outputs:
 * - pointer to head of the users list.
*******************************************************************************/
node_t* load_users(int* total_users)
{
    FILE *fp;

    fp = fopen(DATABASE, "r");

    user_t user;
    node_t* head = (node_t*) malloc(sizeof(node_t));

    if (fp != NULL)
    {
        *total_users = 0;

        while (fgetc(fp) != EOF)
        {
            fseek(fp,-1,SEEK_CUR); /* moves cursor 1 character behind */

            fscanf(fp,"%[^\n]\n", user.login.username);
            fscanf(fp,"%[^\n]\n", user.login.password);
            fscanf(fp, "%[^\n]\n", user.first_name);
            fscanf(fp,"%[^\n]\n", user.last_name);

            fscanf(fp, "%2d%2d%4d\n", &user.DOB.day,
                                      &user.DOB.month,
                                      &user.DOB.year);

            fscanf(fp, "%[^\n]\n", user.phone);
            fscanf(fp,"%[^\n]\n",user.address);
            fscanf(fp, "%[^\n]\n", user.email);
            fscanf(fp, "%f\n", &user.balance);

            user = decrypt(user);

            if (*(total_users)==0)
                head=create_head(user);
            else
                insert_node(head, user);

            ++*(total_users);
        }
        fclose(fp);
    }

    return head;
}
