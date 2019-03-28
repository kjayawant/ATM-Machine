# ATM-Machine
This is a design for the back-end of an ATM machine.

A dummy account is created with the following details: Card Number: 12341234 Pin: 1234 Account Number:1001 Account Balance: $100

Withdrawal function created for denominations any demonination of notes. A map is created for values of notes in ATM and their count. Notes of 20 and 100 are used for demo.

Withdrawal transactions of amount less that or equal to the account balance and the total ATM balance are allowed.

There is a class for Bank which has a map indexed by debit card number and functions for getting account information. Constants are located in header atm.h

The main function is in ConsoleApp.cpp.

Card Number is entered by default as 12341234 for demonstration. Password is then verified.

Following actions can be performed:

    1.Deposit
    2.Withdraw
    3.Get Account Balance
    4.Exit
