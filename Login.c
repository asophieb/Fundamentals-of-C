#include "Login.h"

#define MAX_USERNAME 10
#define MAX_PASSWORD 10
#define DATABASE "user.txt"
/*colours*/
#define RED      "\x1B[31m"
#define GREEN    "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE     "\x1B[34m"
#define PURPLE   "\x1B[35m"
#define CYAN     "\x1B[36m"
#define WHITE    "\x1B[37m"
#define RESET    "\x1B[0m"

#define ADMIN_PASSWORD "password"


/*******************************************************************************
 * Author: Sophie
 * This function searches checks for admin login, otherwise finds and logs in 
 * the user.
 * inputs:
 * - head of the user list.
 * outputs:
 * - null if admin, otherwise a pointer to the user.
*******************************************************************************/
node_t* login(node_t* head)
{
    char username[MAX_USERNAME];
    node_t* node = NULL;

    printf("\n\t\t\t Welcome to Bank\n\n");
    while(node == NULL)
    {
        printf("\t Username:");
        scanf("%s", username);

        if (strcmp(username, "admin") == 0) /*Hard code admin*/
        {
            /*Welcome Administrator*/
            return NULL;/*return when its admin*/
        }
        else
        {
            node = find_node(head, username);
            if(node == NULL)
            {
                printf(RED "\n\t This Username Does Not Exist.\n\n" RESET);
            }
            else
            {
                /*Welcome User*/
                return(node);/*return when is user*/
            }
        }
    }   
    return 0;
}

int user_password(const node_t* node)
{
    char pass[MAX_PASSWORD];
    int exit = 0;
    /*printf("%s\n", saved_password );*/

    while(exit < 5)
    {
        printf("\t Password:");
        system("stty -echo"); /* Turns off character display */
        scanf("%s",pass);
        system("stty echo"); /* Turn echoing of characters back on */

        /*User password compare*/
        if(strcmp(node->user.login.password, pass) != 0) 
        {
            printf(RED "\n\n\t *Wrong Password*\n\n" RESET);
            printf("\t Attempt %d\n",exit);
            exit++;
        }
        else
        {
            printf("\n\n\t Welcome to your Account, %s %s \n\n", 
                    node->user.first_name, node->user.last_name);
            return 1; /*return 1 when user signed in*/
        }
    }

    printf(RED "\n\n\t Sorry you are locked out.\n\n" RESET);
    system("clear");
    return 0;
}

int admin_password()
{
    char pass[MAX_PASSWORD];
    int exit = 1;

    while (exit < 5)
    {
        printf("\t Password:");
        system("stty -echo"); /* Turns off character display */
        scanf("%s",pass);
        system("stty echo"); /* Turn echoing of characters back on */
        
        if(strcmp(ADMIN_PASSWORD, pass) != 0)/*Admin password compear*/
        {
            exit++;
            printf(RED "\n\n\t *Wrong Password*\n\n" RESET);
            printf("\t Attempt %d\n",exit);
        }
        else
            return 1; /* return 1 when admin signed in */
    }
    printf(RED "\n\t Sorry you are locked out.\n" RESET);
    system("clear");
    return 0;
}
