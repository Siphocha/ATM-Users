#include <stdio.h>

//check the balance
void checking_balance(float balance);
//* only for when the function needs to edit value
void depositing(float *balance);
//depositing and withdrawing function declarations
void withdrawing(float *balance);


struct Users { //THIS MAY BE UNECESSARY AS WE NEED PREDEFINED USERS TECHNICALLY.
    //establishing user data structure for use later
    char name[];
    int password;
    struct User *next;
};

int main() {
    //Pre-defined user list
    char username1[] = "Sipho";
    int password1[] = 1;

    char username2[] = "Tejiri";
    int password2[] = 2;

    char username3[] = "Shafii";
    int passsword3[] = 3;

    // memory declarations on pre-defined usernames and password
    int inputPassword1[1];
    char inputUsername1[5];

    int inputPassword2[1];
    char inputUsername2[5];

    int inputPassword3[1];
    char inputUsername3[5];



}