#include <stdio.h>
#include <stdbool.h>

#define ALLOWED_ATTEMPTS 3


//Function Prototypes:
void Bank_System();


int main(void)
{
    Bank_System();
    return 0;
}


void Bank_System()
{
    char selectAuthenticationOption();

    printf(
        "========================================\n"
        "   Welcome to the CLI Banking System\n"
        "========================================\n"
    );
    
    char choiceNumber = selectAuthenticationOption();

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

    return 0; //FAILED!!
}
