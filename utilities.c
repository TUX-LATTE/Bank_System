#include "utilities.h"
#include <stdio.h> 
#include <string.h>  

bool retryInput(void *input, char *format, VALIDATION_RULE validationRule, unsigned char allowedAttempts, char *msg, void *reference)
{
    unsigned char attemptsLeft = allowedAttempts;

    while (attemptsLeft > 0)
    {
        printf("%s (Attempts left => %d): ", msg, attemptsLeft);
        scanf(format, input);

        bool isValid = false;
        switch (validationRule)
        {
            case RULE_OPTION_CHOICE_NUMBER:
                isValid = (*(char *)input == 1 || *(char *)input == 2 || *(char *)input == 3);
                break;
            case RULE_PASSWORD_MATCH:
                isValid = (strcmp((char *)input, (char *)reference) == 0);
                break;
            default:
                break;
        }

        if (isValid)
            return true;

        puts("Invalid Input, please try again!");
        --attemptsLeft;
    }

    return false;
}
