# Bank Account Management System

This is a simple console-based Bank Account Management System that I built in C++. It basically copies what a real bank does on a small scale — you can open an account, deposit money, withdraw money, transfer money to another account, and check your balance. Everything is protected with a 4-digit PIN, just like a real ATM card.

I made this project to practice Object-Oriented Programming (OOP) in C++, especially how classes work, how to store multiple objects in an array, and how to validate user input properly.


## Features

- Create a new bank account
- Deposit money
- Withdraw money
- Transfer money between accounts
- Account inquiry (view full account details)
- Check current balance
- Delete an account
- Login system using Account Number + 4-digit PIN (with a limit of 3 attempts)

## Built With

- **Language:** C++
- **Concepts practiced:** Classes & Objects, Arrays, Loops, Functions, Input Validation


## Menu Options

1: Create Account
2: Deposite Money
3: Withdraw Money
4: Transfer Money
5: Account Inquiry
6: Check Balance
7: Delete Account
0: Exit
```

## How to Run

I built this using **Dev-C++ (Embarcadero)**, so here's how to run it the same way:

1. Download or clone this repository to your computer.
   - Easiest way: click the green **Code** button on the GitHub page → **Download ZIP** → extract it.
   - Or, if you use git:
     ```bash
     git clone https://github.com/khanamir123/your-repo-name.git
     ```

2. Open **Dev-C++**.

3. Go to **File → Open Project or File**, and select `bank_management_system.cpp` from the extracted folder.

4. Once the file is open, just click the **Compile & Run** button (or press **F11**). This does both steps at once — it compiles the code and runs it in a console window.

That's it — the menu (Create Account, Deposit, Withdraw, etc.) will show up in the console window that opens.

### Alternative: Running from terminal (if you don't use Dev-C++)

If someone wants to run it without Dev-C++, they can compile it manually using g++ from a terminal:
```bash
g++ bank_management_system.cpp -o bank_management_system
```
Then run it:
```bash
./bank_management_system
```
On Windows:
```bash
bank_management_system.exe


## How Login Works

Before doing anything with an existing account (deposit, withdraw, transfer, etc.), the program asks the user to log in first using:
- Their **Account Number**
- Their **4-digit PIN**

The user gets **3 attempts**. If all 3 are wrong, the program stops letting them try for that action.


## Limitations

Since this was mainly a learning project, it does have a few limitations I'm aware of:

- Can only store a maximum of **50 accounts** at once (because it uses a fixed-size array)
- Nothing is saved permanently — once the program is closed, all accounts and balances are gone (no file or database is used)
- The PIN is stored as plain text without encryption, so this is for practice purposes only, not something to use for real banking


## Future Improvements

Some things I'm planning to add later as I learn more:

-  Save account data to a file so it doesn't reset every time
-  Add PIN encryption
-  Add a transaction history feature
-  Maybe convert it into a GUI application

---

## Author

Muhammad Amir Khan
GitHub: [khanamir123](https://github.com/khanamir123)
