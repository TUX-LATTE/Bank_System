#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H
#define ALLOWED_ATTEMPTS 2 //The first attempt + two retry attempt

#include <stdbool.h>


typedef enum {
    RULE_AUTH_CHOICE_NUMBER,
    RULE_PASSWORD_MATCH,
} VALIDATION_RULE;


void Bank_System();
char selectAuthenticationOption();
void signInUserAccount();
void signUpUserAccount();
bool retryInput(void *input, char *format, VALIDATION_RULE validationRule, unsigned char allowedAttempts, char *msg, void *reference);



#endif