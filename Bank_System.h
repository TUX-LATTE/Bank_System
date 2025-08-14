#ifndef BANK_SYSTEM_H
#define BANK_SYSTEM_H

#include "file_store.h"
#include "utilities.h"

#include <stdbool.h>
#include <stdio.h>
#include <string.h>

// Enum for authentication options
typedef enum 
{
    SIGN_IN = 1,
    SIGN_UP,
    EXIT,
} AuthenticationOption;

// Enum for banking operations
typedef enum
{
    DEPOSIT = 1,
    WITHDRAW,
    CHECK_BALANCE,
    BACK_TO_BASE,
} BANK_OPERATION;

// Function to run the main banking system
void Bank_System();

// Function to display authentication options and get user input
char selectAuthenticationOption();

// Function to handle user account sign-in
void signInUserAccount();

// Function to handle user account sign-up
void signUpUserAccount();

// Function to handle banking operations like deposit, withdraw, and check balance
void bankOperations();

#endif //BANK_SYSTEM.H