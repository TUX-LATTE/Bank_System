#include "utilities.h"
#include "Bank_System.h"

// Function to retry user input with validation rules
bool retryInput(void *input, char *format, VALIDATION_RULE validationRule, void *reference)
{
    unsigned char attemptsLeft = ALLOWED_ATTEMPTS;

    while (attemptsLeft > 0)
    {
        printf("%s (Attempts left => %d): ", MSG_RETRY, attemptsLeft);
        scanf(format, input);

        bool isValid = false;
        switch (validationRule)
        {
            case RULE_AUTH_CHOICE_NUMBER:
                isValid = (*(char *)input == 1 || *(char *)input == 2 || *(char *)input == 3);
            case RULE_OPTION_CHOICE_NUMBER:
                isValid = (*(char *)input == 1 || *(char *)input == 2 || *(char *)input == 3 || *(char *)input == 4);
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
