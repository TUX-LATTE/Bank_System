#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "Bank_System.h"

void Bank_System()
{
    printf(
        "========================================\n"
        "   Welcome to the CLI Banking System\n"
        "========================================\n"
    );
    
    char choiceNumber = selectAuthenticationOption();
    
    switch (choiceNumber)
    {
        case 1:
            // signInUserAccount();
            break;
        case 2:
            signUpUserAccount();
            break;
        default:
            printf("You entered three invalid inputs\nTerminating..\n");
            return;
    }
}

char selectAuthenticationOption()
{
    char choiceNumber;
    unsigned char attemptsLeft = ALLOWED_ATTEMPTS;
    char *msg = "Please choose an option:\n1. Sign In (Existing Users)\n2. Sign Up (New Users)\nEnter your choice number: ";

    printf("%s", msg);
    scanf("%hhd", &choiceNumber);

    if(choiceNumber == 1 || choiceNumber == 2)
    {
        return choiceNumber;
    }
    else
    {
        if(retryInput(&choiceNumber, "%hhd", (choiceNumber == 1 || choiceNumber == 2), attemptsLeft, msg))
        {
            return choiceNumber;
        }
    }

    return -1; // Failed!
}


// void signInUserAccount()
// {
// }


void signUpUserAccount()
{
    char firstName[30];
    char lastName[30];
    char username[30];
    char password[30];
    char confirmPassword[30];

    printf("%s", "Enter your first name: ");
    scanf("%29s", firstName);

    printf("%s", "Enter your last name: ");
    scanf("%29s", lastName);

    printf("%s", "Enter your username: ");
    scanf("%29s", username);

    printf("%s", "Enter your password: ");
    scanf("%29s", password);

    printf("%s", "Confirm your password: ");
    scanf("%29s", confirmPassword);

    if(strcmp(password, confirmPassword) == 0)
    {
        puts("Registration Done!");
    }
    else
    {
        char *msg = "Passwords do not match, try again: ";
        unsigned char attemptsLeft = ALLOWED_ATTEMPTS;
        
        if(retryInput(confirmPassword, "%29s", (strcmp(password, confirmPassword) == 0), attemptsLeft, msg))
        {
            puts("Registration Done!");
        }
        else
        {
            printf("You entered three invalid inputs\nTerminating..\n");
            return;
        }
    }
}


bool retryInput(void *input, char *format, bool isValid, char attemptsLeft, char *msg)
{
    while (!isValid && attemptsLeft > 0)
    {
        puts("Invalid Input, please try again:");
        --attemptsLeft;

        printf("%s (Attempts Left => %d): ", msg, attemptsLeft);
        scanf(format, input); 
        

        if(isValid && attemptsLeft > 0)
        {
            return isValid;
        }
    }

    return !isValid;
}

