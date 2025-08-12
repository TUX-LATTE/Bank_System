#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H
#define ALLOWED_ATTEMPTS 3

#include <stdbool.h>

void Bank_System();
char selectAuthenticationOption();
void signInUserAccount();
void signUpUserAccount();
bool retryInput(void *input, char *format, bool loopContCond, char attemptsLeft, char *msg);



#endif
