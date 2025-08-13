#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H
#define ALLOWED_ATTEMPTS 2 //The first attempt + two retry attempts = three attempts

#include <stdbool.h>


typedef enum 
{
    SIGN_IN = 1,
    SIGN_UP,
    EXIT
} AuthenticationOption;


void Bank_System();
char selectAuthenticationOption();
void signInUserAccount();
void signUpUserAccount();


#endif //BANK_SYSTEM.H