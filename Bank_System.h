#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H
#define ALLOWED_ATTEMPTS 2 //The first attempt + two retry attempts = three attempts

#include <stdbool.h>


typedef enum 
{
    SIGN_IN = 1,
    SIGN_UP,
    EXIT,
} AuthenticationOption;

typedef enum
{
    DEPOSIT = 1,
    WITHDRAW,
    BACK_TO_BASE,
} BANK_OPERATION;

void Bank_System();
char selectAuthenticationOption();
void signInUserAccount();
void signUpUserAccount();
void bankOperations();


#endif //BANK_SYSTEM.H