#include "stdafx.h"
#include "AtmMachine.h"

/**		ATM Class
 *         Includes functions to deposit and withdraw cash in ATM
 */
using namespace std;

/**
 * Initialize NotesCount, balance in ATM
 * 
 */
void AtmMachine::init() {
	NotesCount[100] = NOTES_OF_100;
	NotesCount[20] = NOTES_OF_20;

	for (auto entry : NotesCount) {
		balance += entry.first*entry.second;
	}
	cout << "\t\tATM";
}

/**
 * Function to withdraw amount from account 
 *
 * @param cardNum - parameter to accept debit dard number
 * @param amount - parameter to accept amount to be withdrawn
 * @return int
 */
int AtmMachine::withdraw(string cardNum, double amount) {
	if (amount < balance) {
		if (amount <= 0) { cout << "Invalid amount"; return -1; }
		if (amount <= ABC.getBal(cardNum))
		{
			int rem = amount;
			for (auto notes : NotesCount) {
				rem = rem%notes.first;
			}
			if (amount == floor(amount) && rem == 0) {

				ABC.setBal(cardNum, ABC.getBal(cardNum) - amount);

				return ABC.getBal(cardNum) - amount;
			}
			else
				cout << "\n\nPlease enter denominations of 100 and/or 20.";
		}
		else
			cout << "\n\nInsufficient account balance.\n";
	}
	else
		cout << "\n\nNot enough cash in ATM.";
	return -1;
}

/**
* Function to deposit amount to an account
*
* @param cardNum - parameter to accept debit dard number
* @param amount - parameter to accept amount to be deposited from Money Counter in ATM
* @return int
*/
int AtmMachine::deposit(string cardNum, double amount) {
	int bal = ABC.getBal(cardNum);
	ABC.setBal(cardNum, bal + amount);
	cout << "\n$" << fixed << setprecision(2) << amount << " deposited to account.";
	return bal + amount;
}