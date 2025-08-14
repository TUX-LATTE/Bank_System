#ifndef UTILITIES_H
#define UTILITIES_H

// Macro for failed operation return value
#define FAILED -1

// Message for retry prompt
#define MSG_RETRY "Invalid input, please try again"

// Number of allowed attempts for user input
#define ALLOWED_ATTEMPTS 2 // The first attempt + two retry attempts = three attempts

#include <stdbool.h>

// Enum for input validation rules
typedef enum 
{
    RULE_AUTH_CHOICE_NUMBER, // Validation for authentication choice
    RULE_PASSWORD_MATCH,     // Validation for password match
    RULE_OPTION_CHOICE_NUMBER // Validation for banking operation choice
} VALIDATION_RULE;

// Function to retry user input with validation rules
bool retryInput(
    void *input,
    char *format,
    VALIDATION_RULE validationRule,
    void *reference
);

#endif // UTILITIES_H
