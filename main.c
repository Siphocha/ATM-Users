#include <stdio.h>
#include <string.h> 

#define MAX_USERS 3
#define MAX_TRANSACTIONS 10 

//Predefined users
char usernames[MAX_USERS][30] = {"Shafi", "Sipho", "Tejiri"};
char pins[MAX_USERS][5] = {"1234", "7777", "4321"};
float balances[MAX_USERS] = {500.0, 1000.0, 2.00};

//memory allocation of transaction logs
char transactions[MAX_TRANSACTIONS][100];
int transaction_count = 0;

//Declaring functions
void checking_balance(float balance);
void depositing(float *balance);
void withdrawing(float *balance);
int login(); 
void log_transaction(const char *desc); 
void view_transactions(); 

//Check Balance
void checking_balance(float balance) {
    printf("Your current balance is: $%.2f\n", balance);
}

//Depositing amount
void depositing(float *balance) {
    float amount;
    printf("Amount to Deposit: $");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("Invalid deposit amount.\n");
    } else {
        *balance += amount;
        printf("Deposited: $%.2f\n", amount);

        // Log transaction
        char desc[100];
        sprintf(desc, "Deposited: $%.2f", amount);
        log_transaction(desc);
    }
}

//Withdraw certain amount
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

        //Transaction logs listing out
        char desc[100];
        sprintf(desc, "Withdrew: $%.2f", amount);
        log_transaction(desc);
    }
}

//Function for logging in
int login() {
    char input_user[20], input_pin[5];
    printf("Username: ");
    scanf("%s", input_user);
    printf("PIN (4-digit): ");
    scanf("%s", input_pin);

    for (int i = 0; i < MAX_USERS; i++) {
        if (strcmp(input_user, usernames[i]) == 0 && strcmp(input_pin, pins[i]) == 0) {
            printf("Login successful. Welcome, %s!\n", input_user);
            return i;
        }
    }

    printf("Login failed. Try again.\n");
    return -1;
}

//Log transaction thereafter
void log_transaction(const char *desc) {
    if (transaction_count < MAX_TRANSACTIONS) {
        strcpy(transactions[transaction_count], desc);
        transaction_count++;
    }
}

//Viewing the transaction history
void view_transactions() {
    printf("\n-- Transaction History --\n");
    if (transaction_count == 0) {
        printf("No transactions yet.\n");
    } else {
        for (int i = 0; i < transaction_count; i++) {
            printf("%d. %s\n", i + 1, transactions[i]);
        }
    }
}

int main() {
    int user_index = -1;
    int option; 
    float current_balance; 

    // Login
    while (user_index == -1) {
        user_index = login();
    }

    // Set balance for this user
    current_balance = balances[user_index];

    do {
        printf("\n==== ATM MENU ====\n");
        printf("1. Check Balance\n");
        printf("2. Deposit\n");
        printf("3. Withdraw\n");
        printf("4. Exit\n");
        printf("5. View Transaction History\n");
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
                withdrawing(&current_balance);
                break;
            case 4:
                printf("Thank you for using the ATM.\n");
                break;
            case 5:
                view_transactions();
                break;
            default:
                printf("Invalid option. Try again.\n");
        }

    } while(option != 4);

    //Updating balance back to that specific users account
    balances[user_index] = current_balance;

    return 0;
}
