#include "stdafx.h"
#include "Bank.h"

using namespace std;

/**
 * @brief Construct a new Bank:: Bank object
 *
 */
Bank::Bank() {
		AccountInfo demo;
		demo.accountNum = DEMO_ACCOUNT_NUM;
		demo.pin = DEMO_PIN;
		demo.accountBalance = DEMO_BAL;
		Bank::AccountList[DEMO_CARD_NUM] = demo;
	}

/**
 * @brief Function to verify pin from the bank database
 *
 * @param cardNum - debit card number
 * @param pin - debit card pin
 * @return true
 * @return false
 */
bool Bank::verify_pin(string cardNum, int pin) {
		if (AccountList[cardNum].pin == pin) {
			return true;
		}
		return false;
	}


/**
* @brief Get account balance from bank
*
* @param cardNum - debit card number
* @return double
*/
double Bank::getBal(string cardNum) {
		return AccountList[cardNum].accountBalance;
	}


/**
* @brief Update account balance
*
* @param cardNum - debit card number
* @param bal
*/
void Bank::setBal(string cardNum, int bal) {
	AccountList[cardNum].accountBalance = bal;
}