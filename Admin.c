#include "Admin.h"

#define RED      "\x1B[31m"
#define GREEN    "\x1B[32m"
#define YELLOW   "\x1B[33m"
#define BLUE     "\x1B[34m"
#define PURPLE   "\x1B[35m"
#define CYAN     "\x1B[36m"
#define WHITE    "\x1B[37m"
#define RESET    "\x1B[0m"

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
    char username[MAX_USERNAME_LEN];
    char confirm;
    node_t* node;

    while(1)
    {
        system("clear");
        printf("Enter the user ID of the user to be deleted > ");
        scanf("%s", username);
        node = find_node(head, username);

        if(node != NULL)
        {
            system("clear");
            print_user(node->user);
            printf(YELLOW"Do you want to delete this user? y or n > "RESET);
            scanf(" %c", &confirm);
            if(strcmp(&confirm, "y"))
            {
                remove_node(head, node);
                system("clear");
                break;
            }
            else
            {
                printf("User will not be deleted.\n");
                break;
            }
        }

        else
        {
            printf(RED"Please enter a valid choice.\n"RESET);
            break;
        }
    }

}

/*******************************************************************************
 * Author: Sophie
 * This function allows the user to edit user information.
 * inputs:
 * - reference to the property to change
 * - the name of the propertry to change
 * outputs:
 * - none
*******************************************************************************/
void edit_user(char* property, char* property_name)
{
    char placeholder[256];
    char confirm;

    /* ask for the new value */
    while(1)
    {               
        printf("Enter the new %s > ", property_name);
        scanf("%s", placeholder);

        if(is_valid_name(placeholder))
        {
            system("clear");
            printf("The user's %s will change from %s to %s", 
                property_name, property, placeholder);
            break;
        }
        else
        {
            printf(RED"Please enter a valid %s.\n\n"RESET, property_name);
        }
    }

    /* confirm the change */
    while(1)
    {
        printf("\nDo you accept this change? y or n > ");
        scanf(" %c", &confirm);

        if(confirm == 'y' || confirm == 'Y')
        {
            strcpy(property, placeholder);
            system("clear");
            printf("User's %s has been changed to %s.\n", 
                    property_name, property);
            break;
        }
        else if(confirm == 'n' || confirm == 'N')
        {
            system("clear");
            printf(YELLOW"Change has been discarded.\n"RESET);
            
            break;
        }
        else
        {
            printf(RED"please enter valid choice.\n"RESET);
        }
    }   
}

void change_password(node_t* head, node_t* node)
{
    char placeholder[256];
    char confirm;

    while(1)
    {               
        printf("Enter the new password > ");
        scanf("%s", placeholder);

        if(is_valid_password(placeholder))
        {
            system("clear");
            printf("The user's password will changed to %s", 
                placeholder);
            break;
        }
        else
        {
            printf(RED"Please enter a valid password.\n");
            printf("the password must contain a uppercase "
                   "lowercase letter and a number.\n"RESET);
        }
    }

    while(1)
    {
        printf(YELLOW"\nDo you accept this change? y or n > "RESET);
        scanf(" %c", &confirm);

        if(confirm == 'y' || confirm == 'Y')
        {
            strcpy(node->user.login.password, placeholder);
            system("clear");
            printf("User's password has been changed to %s.\n", 
                    node->user.login.password);

            break;
        }

        else if(confirm == 'n' || confirm == 'N')
        {
            system("clear");
            printf(YELLOW"Change has been discarded.\n"RESET);

            break;
        }

        else
        {
            printf(RED"please enter valid choice.\n"RESET);
        }
    }   
}

void edit_info_menu(node_t* head)
{   
    char placeholder[256];
    char confirm;
    char choice[MAX_USERNAME_LEN];
    int day, month, year;
    node_t* node;

    while(1)
    {
        system("clear");
        printf("Enter the user ID of the user to be edited > ");
        scanf("%s", choice);
        if(find_node(head, choice) != NULL)
        {
            node = find_node(head, choice);
            while(1)
            {
                printf(GREEN"\n\t\t\tUser Information Editor"RESET
                   "\n1. First Name"
                   "\n2. Last Name"
                   "\n3. Date Of Birth"
                   "\n4. Phone Number"
                   "\n5. Email Address"
                   "\n6. Home Address"
                   "\n7. Username"
                   "\n8. Password"
                   "\n9. View User Information"
                   "\n0. Exit Editor"
                   "\nEnter choice (Between 0-9)>\n");
                
                int i = 0;
                /* Scans input from the user and directs the user to the right function.*/
                scanf("%d", &i);
                while(getchar()!='\n');
                system("clear");
                
                switch (i)
                { /* Comment out get each case to test each function works. */
                    case 1:                             
                        edit_user(node->user.first_name, "first name");
                        break;
                    case 2: 
                        edit_user(node->user.last_name, "last name");
                        break;
                    case 3:
                        while(1)
                        {               
                            printf("Enter the new Date of Birth dd/mm/yyyy> ");
                            scanf("%d/%d/%d", &day, &month, &year);

                            if(is_valid_DOB(day, month, year))
                            {
                                system("clear");
                                printf("The user's Date of Birth will change from " 
                                       "%d/%d/%d to %d/%d/%d", 
                                        node->user.DOB.day, 
                                        node->user.DOB.month, 
                                        node->user.DOB.year, 
                                        day, month, year);
                                break;
                            }
                            else
                            {
                                printf(RED"Please enter a valid Date of Birth.\n\n"RESET);
                            }
                        }

                        while(1)
                        {
                            printf("\nDo you accept this change? y or n > ");
                            scanf(" %c", &confirm);

                            if(confirm == 'y' || confirm == 'Y')
                            {
                                node->user.DOB.day = day;
                                node->user.DOB.month = month;
                                node->user.DOB.year = year;

                                system("clear");
                                printf("User's Date of Birth has been changed to "
                                       "%d/%d/%d.\n",
                                        node->user.DOB.day, 
                                        node->user.DOB.month, 
                                        node->user.DOB.year);
                                printf("---------------------------------\n");
                                break;
                            }

                            else if(confirm == 'n' || confirm == 'N')
                            {
                                system("clear");
                                printf(YELLOW"Change has been discarded.\n"RESET);
                    
                                break;
                            }

                            else
                            {
                                printf(RED"please enter valid choice.\n"RESET);
                            }
                        }   
                        break;
                    case 4: 
                        while(1)
                        {               
                            printf("Enter the new phone number > ");
                            scanf("%s", placeholder);

                            if(is_valid_phone(placeholder))
                            {
                                system("clear");
                                printf("The user's phone number will change from %s to %s", 
                                    node->user.phone, placeholder);
                                break;
                            }
                            else
                            {
                                printf(RED"Please enter a valid phone number.\n\n"RESET);
                            }
                        }

                        while(1)
                        {
                            printf(YELLOW"\nDo you accept this change? y or n > "RESET);
                            scanf(" %c", &confirm);

                            if(confirm == 'y' || confirm == 'Y')
                            {
                                strcpy(node->user.phone, placeholder);
                                system("clear");
                                printf("User's phone number has been changed to %s.\n", 
                                        node->user.phone);
                                break;
                            }

                            else if(confirm == 'n' || confirm == 'N')
                            {
                                system("clear");
                                printf(YELLOW"Change has been discarded.\n"RESET);
            
                                break;
                            }

                            else
                            {
                                printf(RED"please enter valid choice.\n"RESET);
                            }
                        }   
                        break;
                    case 5:
                        while(1)
                        {               
                            printf("Enter the new email > ");
                            scanf("%s", placeholder);

                            if(is_valid_email(placeholder))
                            {
                                system("clear");
                                printf("The user's email will change from %s to %s", 
                                    node->user.email, placeholder);
                                break;
                            }
                            else
                            {
                                printf(RED"Please enter a valid email.\n\n"RESET);
                            }
                        }

                        while(1)
                        {
                            printf(YELLOW"\nDo you accept this change? y or n > "RESET);
                            scanf(" %c", &confirm);

                            if(confirm == 'y' || confirm == 'Y')
                            {
                                strcpy(node->user.email, placeholder);
                                system("clear");
                                printf("User's email has been changed to %s.\n", 
                                        node->user.email);
                
                                break;
                            }

                            else if(confirm == 'n' || confirm == 'N')
                            {
                                system("clear");
                                printf(YELLOW"Change has been discarded.\n"RESET);
                                break;
                            }

                            else
                            {
                                printf(RED"please enter valid choice.\n"RESET);
                            }
                        }   
                        break;
                    case 6: 
                        printf("Enter the new address > ");
                        scanf("%[^\n]",placeholder);

                        system("clear");
                        printf("The user's address will change from %s to %s\n", 
                                node->user.address, placeholder);

                        while(1)
                        {
                            printf(YELLOW"\nDo you accept this change? y or n > "RESET);
                            scanf(" %c", &confirm);

                            if(confirm == 'y' || confirm == 'Y')
                            {
                                strcpy(node->user.address, placeholder);
                                system("clear");
                                printf("User's address has been changed to %s.\n", 
                                        node->user.address);

                                break;
                            }

                            else if(confirm == 'n' || confirm == 'N')
                            {
                                system("clear");
                                printf(YELLOW"Change has been discarded.\n"RESET);
                        
                                break;
                            }

                            else
                            {
                                printf(RED"please enter valid choice.\n"RESET);
                            }
                        }   

                        break;
                    case 7:

                        while(1)
                        {               
                            printf("Enter the new username > ");
                            scanf("%s", placeholder);

                            if(is_valid_username(placeholder))
                            {
                                system("clear");
                                printf("The user's username will change from %s to %s", 
                                    node->user.login.username, placeholder);
                                break;
                            }
                            else
                            {
                                printf(RED"Please enter a valid username.\n\n"RESET);
                            }
                        }

                        while(1)
                        {
                            printf(YELLOW"\nDo you accept this change? y or n > "RESET);
                            scanf(" %c", &confirm);

                            if(confirm == 'y' || confirm == 'Y')
                            {
                                strcpy(node->user.login.username, placeholder);
                                system("clear");
                                printf("User's username has been changed to %s.\n", 
                                        node->user.login.username);
                
                                break;
                            }

                            else if(confirm == 'n' || confirm == 'N')
                            {
                                system("clear");
                                printf(YELLOW"Change has been discarded.\n"RESET);
                
                                break;
                            }

                            else
                            {
                                printf(RED"please enter valid choice.\n"RESET);
                            }
                        }   

                        break;
                    case 8: 
                        change_password(head, node);
                        break;
                    case 9:
                        print_user(node->user);
                        break; 
                    case 0:
                        return;
                    default:
                        printf(RED"Invalid choice.\n"RESET);
                }
            }
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

    while(1)
    {
        printf("Enter the User ID of a specific user or press * to print all > ");
        scanf("%s", choice);

        if(!(strcmp(choice, "*")))
        {
            print_all_users(head);
            printf("Press enter to continue.");
            while (getchar()!='\n');
            break;
        }

        else if(find_node(head, choice) != NULL)
        {
            node_t* node = find_node(head, choice);
            print_user(node->user);
            printf("Press enter to continue.");
            while (getchar()!='\n');
            break;
        }

        else if(find_node(head, choice) == NULL)
        {
            printf("Please enter a valid user.\n");
        }

        else
        {
            printf("Please enter a valid choice.\n");
        }
    }
}