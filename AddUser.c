#define TRUE 1
#define FALSE 0

#define MAX_FIRSTNAME_LEN 30
#define MAX_LASTNAME_LEN
#define MAX_EMAIL_LEN 256
#define MAX_ADDRESS_LEN 256

/*******************************************************************************
* Struct Defined Structures
 ******************************************************************************/
 struct DOB
 {
     unsigned int day;
     unsigned int month;
     unsigned int year;
 };
 typedef struct DOB DOB_t;

 struct user
 {
     char first_name[MAX_FIRSTNAME_LEN];
     char last_name[MAX_LASTNAME_LEN];
     DOB_t DOB;
     unsigned int phone;
     char email[MAX_EMAIL_LEN];
     char address[MAX_ADDRESS_LEN];
 };
typedef struct user user_t;


/*******************************************************************************
 * This function adds a user in RAM with all instructions on how to use
 * this program.
 * inputs:
 * - users_t* users_p ; points to the elements of users array
 * - int total_users; stores the number of flights currently stored in
 *   users array
 * outputs:
 * - none
*******************************************************************************/
void add_user(user_t* users_p, int total_users)
{
    /* Get First Name */
    while(1)
    {
        printf("First Name>\n ");

        scanf("%[^\n]", users_p[total_users].first_name);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate first name */
        if(is_name_valid(users_p[total_users].first_name)==TRUE)
        {
            break;
        }

        printf("Invalid input. Do not enter any symbol.\n");
    }

    /* Get Last Name */
    while(1)
    {
        printf("Last Name>\n");

        scanf("%[^\n]", users_p[total_users].last_name);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate last name*/
        if(is_name_valid(users_p[total_users].last_name)==TRUE)
        {
            break;
        }

        printf("Invalid input. Do not enter any symbol\n");
    }

    /* Get DOB */
    while(1)
    {
        printf("DOB (dd/mm/yyyy)>\n");

        scanf("%d/%d/%d", &users_p[total_users].DOB.day,
                          &users_p[total_users].DOB.month,
                          &users_p[total_users].DOB.year);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate DOB */
        if(is_valid_DOB( users_p[total_users].DOB.day,
                         users_p[total_users].DOB.month,
                         users_p[total_users].DOB.year)==TRUE)
        {
            break;
        }

        printf("Invalid input\n");
    }


    /* Get Phone Number */
    while(1)
    {
        printf("Phone>\n ");

        scanf("%d", &users_p[total_users].phone);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate phone
        if(is_phone_valid(users_p[total_users].phone)==TRUE)
        {
            break;
        }*/

        printf("Invalid input\n");
    }

    /* Get Email */
    while(1)
    {
        printf("Email>\n ");

        scanf("%[^\n]", users_p[total_users].email);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate email
        if(is_email_valid(users_p[total_users].email)==TRUE)
        {
            break;
        }*/

        printf("Invalid input\n");
    }

    /* Get Address */
    while(1)
    {
        printf("Address>\n ");

        scanf("%[^\n]", users_p[total_users].address);

        /* clears the input buffer */
        while (getchar()!='\n');

        /* validate address
        if(is_name_address(users_p[total_users].address)==TRUE)
        {
            break;
        }*/

        printf("Invalid input\n");
    }
}
