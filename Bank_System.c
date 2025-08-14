#include "Bank_System.h"


// Main function to run the banking system loop
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
                puts("You entered three invalid inputs\nTerminating..\n");
                return;
        }
    }
}


// Function to display authentication options and get user input
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
        if(retryInput(&choiceNumber, "%hhd", RULE_AUTH_CHOICE_NUMBER, NULL))
        {
            return choiceNumber;
        }
    }

    return FAILED;
}


// void signInUserAccount()
// {

// }


// Function to handle user account sign-up
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
            saveData(newUser.firstName, newUser.lastName, newUser.username, newUser.password);
            puts("Registration Done!\nGoing to sign in page\n");
            // signInUserAccount();
            // bankOperations(); (MOVE IT TO signInUserAccount())
    }
    else
    {
        
        if(retryInput(confirmPassword, "%29s", RULE_PASSWORD_MATCH, newUser.password))
        {
            goto registerationSuccess;
        }
        else
        {
            puts("You entered three invalid inputs\nTerminating..\n");
        }
    }
}


// Function to handle banking operations like deposit, withdraw, and check balance
void bankOperations()
{
    puts("\n");

    double accountBalance = 0;
    while(1)
    {
        char operationChoice;
        double transactionAmount; //Move it to the suitable place later

        printf("%s", "Select Operation:\n1. Deposit\n2. Withdraw\n3. Check Balance\n4. Back To Base\nEnter the operation number: ");
        scanf("%hhd", &operationChoice);

        switch (operationChoice)
        {
            
            case DEPOSIT:
                deposit:
                    transactionAmount = 0;

                    printf("%s", "Enter deposit amount: ");
                    scanf("%lf", &transactionAmount);

                    accountBalance += transactionAmount;

                    break;  
                
            case WITHDRAW:
                withdraw:
                    transactionAmount = 0;

                    printf("%s", "Enter withdrawal amount: ");
                    scanf("%lf", &transactionAmount);

                    if(accountBalance >= transactionAmount && transactionAmount >= 0)
                        accountBalance -= transactionAmount;
                    else
                        puts("Insufficient funds. Please enter a smaller amount.");

                    break;

            case CHECK_BALANCE:
                checkBalance:
                    printf("$\n%.2f\n", accountBalance);
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


                    if(operationChoice == CHECK_BALANCE)
                        goto checkBalance;

                    goto backToBase;

                }

                else
                {
                    puts("You entered three invalid inputs\nGetting back to the base..\n");
                }
        }
    }
}