#include <stdio.h>

void checking_balance(float balance);
//* only for when the function needs to edit value
void depositing(float *balance);
void withdrawing(float *balance);


struct Users {
    //establishing user data structure
    char name[];
    int password;
    struct User *next;
};

int main() {
    //main elements of program will go here.
}