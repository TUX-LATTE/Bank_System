#ifndef UTILITIES_H
#define UTILITIES_H

#define FAILED -1
#define MSG_RETRY "Invalid input, please try again"
#define ALLOWED_ATTEMPTS 2 //The first attempt + two retry attempts = three attempts

#include <stdbool.h>


typedef enum 
{
    RULE_AUTH_CHOICE_NUMBER,
    RULE_PASSWORD_MATCH,
    RULE_OPTION_CHOICE_NUMBER,
} VALIDATION_RULE;


bool retryInput(
    void *input,
    char *format,
    VALIDATION_RULE validationRule,
    void *reference
);


#endif // UTILITIES_H
