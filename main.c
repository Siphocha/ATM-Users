#include <stdio.h>

// Function declarations
void checking_balance(float balance);
void depositing(float *balance);
void withdrawing(float *balance);

// Check balance
void checking_balance(float balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

// Deposit
void depositing(float *balance) {
    float amount;
    printf("Amount to Deposit: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
    } else {
        *balance += amount;
        printf("Deposited: $%.2f\n", amount);
    }
}

// Withdraw (YOUR PART)
void withdrawing(float *balance) {
    float amount;
    printf("Amount to Withdraw: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid amount.\n");
    } else if (amount > *balance) {
        printf("Insufficient funds.\n");
    } else {
        *balance -= amount;
        printf("Withdrawn: $%.2f\n", amount);
    }
}

int main() {
    float current_balance = 500.0;
    int option;

    do {
        printf("\n==== ATM MENU ====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("Choose an option: ");
        scanf("%d", &option);

        switch(option) {
            case 1:
                checking_balance(current_balance);
                break;
            case 2:
                depositing(&current_balance);
                break;
            case 3:
                withdrawing(&current_balance); // ← YOUR FUNCTION
                break;
            case 4:
                printf("Thank you for using the ATM.\n");
                break;
            default:
                printf("Invalid option. Try again.\n");
        }

    } while(option != 4);

    return 0;
}
