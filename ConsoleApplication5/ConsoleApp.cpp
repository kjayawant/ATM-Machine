// ConsoleApplication5.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "AtmMachine.h"
#include "Bank.h"

using namespace std;

int main() {
	AtmMachine machine_a;
	int pin,choice;
	machine_a.init();
	bool ongoing = false;
	
	while (1) {
		cout << "\n\n_______________________________\nInsert Card.";
		cout << "\nEnter 4-digit pin:"; //Enter 1234
		cin >> pin;
		while (cin.fail() || !machine_a.ABC.verify_pin(DEMO_CARD_NUM, pin)){
			cin.clear(); cin.ignore(10, '\n');
			cout << "\nIncorrect Pin. Retry\n";
			cin >> pin;
		}
		ongoing = true;
		while (ongoing == true) {
			cout << "\n\n_______________________________\nWhat do you want to do? Please select a number.\n\n1.Deposit\t\t2.Withdraw\t\t3.Get Account Balance\t\t4.Log Out\n";
			cin >> choice;

			switch (choice) {
			case 1: {cout << "Insert cash."; machine_a.deposit(DEMO_CARD_NUM, DEMO_DEPOSIT); cout << "\nAccount Balance: " << machine_a.ABC.getBal(DEMO_CARD_NUM); break; }
			case 2: {double amount; cout << "\nEnter the amount to be withdrawn: "; cin >> amount; cin.clear(); cin.ignore(10, '\n');
				machine_a.withdraw(DEMO_CARD_NUM, amount);
				cout << "\nAccount Balance: " << fixed << setprecision(2) << machine_a.ABC.getBal(DEMO_CARD_NUM); break; }
			case 3: {cout << "\nAccount Balance: $" << fixed << setprecision(2) << machine_a.ABC.getBal(DEMO_CARD_NUM); break; }
			case 4: {ongoing = false; break; };
			default: { cout << "\nInvalid Choice"; cin.clear(); cin.ignore(10, '\n'); };
			}
		}
	}
	return 0;
}