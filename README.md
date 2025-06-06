 C ATM Simulator

 Problem Statement

This project is a simulation of a basic ATM (Automated Teller Machine) system built in the C programming language. It allows predefined users to log in using a username and PIN, and perform banking operations such as checking balance, depositing money, withdrawing funds, and viewing a simple transaction log.

The project demonstrates real-world use of **functions**, **arrays**, **strings**, **control structures**, and **modular design** in C programming. It was developed as part of a Week 5 group assignment for our programming module.

 ‍ Team Members and Contributions

| Name        | Contribution                                                                 |
|-------------|------------------------------------------------------------------------------|
| Sipho       | Set up initial project structure, implemented user login & authentication.  |
| Tejiri      | Wrote `withdraw()` and `check_balance()` functions, built ATM menu system.  |
| Shafii      | Handled `deposit()` function and helped debug logic for transaction actions.|

Each member actively participated in the logic planning and testing phases. Git was used for version control, and all work was tracked in the commit history.


Key Features

- ✅ **Predefined users** with usernames and 4-digit PINs
- ✅ Modular functions:
  - `check_balance()`
  - `deposit()`
  - `withdraw()`
- ✅ ATM menu with continuous loop until logout
- ✅ Simple **transaction log** (text-based)
- ✅ Basic **input validation**
-✅  Clean, readable C code using best practices



Assumptions

- The ATM only supports **3 predefined users**.
- Each user starts with an initial balance of **$500**.
- PINs are **numeric (1, 2, 3)** and not encrypted.
- The transaction log is not persistent (resets on restart).


 How to Compile & Run

Make sure you have **GCC** installed.

bash                                                                                                                                                                                       # Clone the repository
git clone https://github.com/Siphocha/ATM-Users.git

# Navigate into the project directory
cd ATM-Users

# Compile the code
gcc main.c -o atm

# Run the executable
./atm
