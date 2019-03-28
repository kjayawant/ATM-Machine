#pragma once
#include <map>
#include "constants.h"

struct AccountInfo {
	int accountNum;
	int pin;
	double accountBalance;
};

class Bank
{
public:
	std::map <std::string, AccountInfo> AccountList;

	Bank();
	bool verify_pin(std::string cardNum, int pin);
	double getBal(std::string cardNum);
	void setBal(std::string cardNum, int bal);
};
