#include <string.h>
#include <stdio.h>

#include "Encrypt.h"

char* XOR(char* string, char key)
{
    int i;

    for(i=0; string[i]!='\0'; i++)
    {
        string[i]=string[i] ^ key;
    }

    return string;

}

user_t encrypt(user_t user)
{
    char XORkey = '!';

    user_t temp_user;

    strcpy(temp_user.login.username,XOR(user.login.username, XORkey));
    strcpy(temp_user.login.password,XOR(user.login.password, XORkey));

    strcpy(temp_user.first_name,XOR(user.first_name, XORkey));
    strcpy(temp_user.last_name,XOR(user.last_name, XORkey));

    temp_user.DOB.day=user.DOB.day ^ XORkey;
    temp_user.DOB.month=user.DOB.month ^ XORkey;
    temp_user.DOB.year=user.DOB.year ^ XORkey;

    strcpy(temp_user.phone,XOR(user.phone, XORkey));
    strcpy(temp_user.email,XOR(user.email, XORkey));
    strcpy(temp_user.address,XOR(user.address, XORkey));

    /* XOR operator cannot be used with floating numbers */

    /*We are only considering 2 decimal places for the balance
      So we multiply by 100 to make it a whole number*/

    int temp_balance;
    temp_balance = (int)user.balance*100;
    temp_user.balance=(float) (temp_balance ^ XORkey);

    return temp_user;
}

user_t decrypt(user_t user)
{
    char XORkey = '!';

    user_t temp_user;

    strcpy(temp_user.login.username,XOR(user.login.username, XORkey));
    strcpy(temp_user.login.password,XOR(user.login.password, XORkey));

    strcpy(temp_user.first_name,XOR(user.first_name, XORkey));
    strcpy(temp_user.last_name,XOR(user.last_name, XORkey));

    temp_user.DOB.day=user.DOB.day ^ XORkey;
    temp_user.DOB.month=user.DOB.month ^ XORkey;
    temp_user.DOB.year=user.DOB.year ^ XORkey;

    strcpy(temp_user.phone,XOR(user.phone, XORkey));
    strcpy(temp_user.email,XOR(user.email, XORkey));
    strcpy(temp_user.address,XOR(user.address, XORkey));

    /* XOR operator cannot be used with floating numbers */

    /* The encrypted file converted it to a whole number
       by multiplying it with 100. So, we divide by 100
       to make it a floating number equal to the original balance*/

    int temp_balance;
    temp_balance=(int) user.balance ^ XORkey;
    temp_user.balance=(float)temp_balance / 100;

    return temp_user;
}
