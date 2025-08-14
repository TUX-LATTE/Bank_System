#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H


#include <stdbool.h>
#include <stdio.h>
#include <string.h>


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
    CHECK_BALANCE,
    BACK_TO_BASE,
} BANK_OPERATION;

void Bank_System();
char selectAuthenticationOption();
void signInUserAccount();
void signUpUserAccount();
void bankOperations();


#endif //BANK_SYSTEM.H