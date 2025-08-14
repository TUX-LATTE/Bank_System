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

    printf("%s", "Please choose an option:\n1. Sign In (Existing Users)\n2. Sign Up (New Users)\n3. Exit\nEnter your choice number: ");
    scanf("%hhd", &choiceNumber);

    if(choiceNumber == 1 || choiceNumber == 2 || choiceNumber == 3)
    {
        return choiceNumber;
    }
    else
    {
        if(retryInput(&choiceNumber, "%hhd", RULE_OPTION_CHOICE_NUMBER, NULL))
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
        registerationSuccess:
            puts("Registration Done!");
            bankOperations();
    }
    else
    {
        
        if(retryInput(confirmPassword, "%29s", RULE_PASSWORD_MATCH, newUser.password))
        {
            goto registerationSuccess;
        }
        else
        {
            printf("You entered three invalid inputs\nTerminating..\n");
            return;
        }
    }
}


void bankOperations()
{
    puts("\n");

    double accountBalance = 0;
    while(1)
    {
        char operationChoice;

        printf("Select Operation:\n1. Deposit\n2. Withdraw\n3. Back To Base\nEnter the operation number: ");
        scanf("%hhd", &operationChoice);

        switch (operationChoice)
        {
            case DEPOSIT:
                deposit:
                    puts("From deposit");
                    break;  
                
            case WITHDRAW:
                withdraw:
                    puts("From withdraw");
                    break;
            
            case BACK_TO_BASE:
                backToBase:
                    puts("BACK TO THE BASE");
                    return;
            default:
                if(retryInput(&operationChoice, "%hhd", RULE_OPTION_CHOICE_NUMBER, NULL))
                {
                    if(operationChoice == DEPOSIT)
                        goto deposit;

                    if(operationChoice == WITHDRAW)
                        goto withdraw;

                    goto backToBase;

                }
                else
                {
                    printf("You entered three invalid inputs\nGetting back to the base..\n");
                }
        }
    }
}