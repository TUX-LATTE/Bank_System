#include <stdio.h>
#include <string.h>

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

    while (attemptsLeft > 0)
    {
        printf(
            "Please choose an option:\n"
            "1. Sign In (Existing Users)\n"
            "2. Sign Up (New Users)\n"
            "Enter your choice number: "
        );

        scanf("%hhd", &choiceNumber);

        if (choiceNumber == 1 || choiceNumber == 2)
        {
            return choiceNumber;
        }

        attemptsLeft--;

        if (attemptsLeft > 0)
        {
            printf("\nInvalid input! Try again (attempts left: %u)\n\n", attemptsLeft);
        }
    }

    return 0; // FAILED
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

    printf("%s", "Enter your last nane: ");
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
        puts("Passwords do not match");
        return;
    }
}