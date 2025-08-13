#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "Bank_System.h"
#include "utilities.h"

void Bank_System()
{
    while(1)
    {
        printf(
            "========================================\n"
            "   Welcome to the CLI Banking System\n"
            "========================================\n"
        );
        
        unsigned char choice = selectAuthenticationOption();
        
        switch (choice)
        {
            case SIGN_IN:
                // signInUserAccount();
                break;
            case SIGN_UP:
                signUpUserAccount();
                break;
            case EXIT:
                puts("GOOD BYE!");
                return;
            default:
                printf("You entered three invalid inputs\nTerminating..\n");
                return;
        }
    }
}

char selectAuthenticationOption()
{
    unsigned char choiceNumber;
    char *msg = "Please choose an option:\n1. Sign In (Existing Users)\n2. Sign Up (New Users)\n3. Exit\nEnter your choice number: ";

    printf("%s", msg);
    scanf("%hhd", &choiceNumber);

    if(choiceNumber == 1 || choiceNumber == 2 || choiceNumber == 3)
    {
        return choiceNumber;
    }
    else
    {
        if(retryInput(&choiceNumber, "%hhd", RULE_AUTH_CHOICE_NUMBER, ALLOWED_ATTEMPTS, msg, NULL))
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
    struct
    {
        char firstName[30];
        char lastName[30];
        char username[30];
        char password[30];
        // char confirmPassword[30];
    }newUser;
    

    printf("%s", "Enter your first name: ");
    scanf("%29s", newUser.firstName);

    printf("%s", "Enter your last name: ");
    scanf("%29s", newUser.lastName);

    printf("%s", "Enter your username: ");
    scanf("%29s", newUser.username);

    printf("%s", "Enter your password: ");
    scanf("%29s", newUser.password);

    char confirmPassword[30];
    printf("%s", "Confirm your password: ");
    scanf("%29s", confirmPassword);

    if(strcmp(newUser.password, confirmPassword) == 0)
    {
        puts("Registration Done!");
    }
    else
    {
        char *msg = "Passwords do not match, try again: ";
        
        if(retryInput(confirmPassword, "%29s", RULE_PASSWORD_MATCH, ALLOWED_ATTEMPTS, msg, newUser.password))
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