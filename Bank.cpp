#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Maximum number of accounts
#define MAX_ACCOUNTS 100

// Account structure
struct Account {
    int accountNumber;
    char name[50];
    float balance;
    int accountType; // 1 for Savings, 2 for Checking
};

struct Account accounts[MAX_ACCOUNTS];
int numAccounts = 0;

// Function to create a new account
void createAccount() {
    if (numAccounts >= MAX_ACCOUNTS) {
        printf("Account limit reached.\n");
        return;
    }

    struct Account newAccount;
    printf("Enter account number: ");
    scanf("%d", &newAccount.accountNumber);
    printf("Enter account holder's name: ");
    scanf("%s", newAccount.name);
    printf("Enter initial deposit: ");
    scanf("%f", &newAccount.balance);
    printf("Choose account type (1 for Savings, 2 for Checking): ");
    scanf("%d", &newAccount.accountType);

    accounts[numAccounts] = newAccount;
    numAccounts++;
    printf("Account created successfully!\n");
}

// Function to deposit money
void deposit() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            accounts[i].balance += amount;
            printf("Deposit successful! New balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to withdraw money
void withdraw() {
    int accountNumber;
    float amount;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            if (accounts[i].balance >= amount) {
                accounts[i].balance -= amount;
                printf("Withdrawal successful! New balance: %.2f\n", accounts[i].balance);
            } else {
                printf("Insufficient funds.\n");
            }
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to check balance
void checkBalance() {
    int accountNumber;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            printf("Account holder: %s\n", accounts[i].name);
            printf("Account balance: %.2f\n", accounts[i].balance);
            return;
        }
    }
    printf("Account not found.\n");
}

// Function to calculate interest
void calculateInterest() {
    int accountNumber;
    float interestRate;
    printf("Enter account number: ");
    scanf("%d", &accountNumber);

    for (int i = 0; i < numAccounts; i++) {
        if (accounts[i].accountNumber == accountNumber) {
            if (accounts[i].accountType == 1) {
                // Savings account interest rate (example: 4%)
                interestRate = 0.04;
            } else {
                // Checking account interest rate (example: 2%)
                interestRate = 0.02;
            }

            float interest = accounts[i].balance * interestRate;
            printf("Interest for account %d is: %.2f\n", accountNumber, interest);
            return;
        }
    }
    printf("Account not found.\n");
}

// Main program
int main() {
    int choice;

    while (1) {
        printf("\nBank Account Management System:\n");
        printf("1. Create Account\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Check Balance\n");
        printf("5. Calculate Interest\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createAccount();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                calculateInterest();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}
