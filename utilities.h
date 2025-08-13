#ifndef UTILITIES_H
#define UTILITIES_H

#include <stdbool.h>

typedef enum {
    RULE_AUTH_CHOICE_NUMBER,
    RULE_PASSWORD_MATCH,
} VALIDATION_RULE;

bool retryInput(
    void *input,
    char *format,
    VALIDATION_RULE validationRule,
    unsigned char allowedAttempts,
    char *msg,
    void *reference
);

#endif // UTILITIES_H
