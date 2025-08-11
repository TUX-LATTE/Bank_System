#include <stdio.h>
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
            // signUpUserAccount();
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

// void signUpUserAccount()
// {
// }
