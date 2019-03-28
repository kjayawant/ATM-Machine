#pragma once
#include <vector>
#include <iostream>
#include <unordered_map>
#include <iomanip>
#include "Bank.h"

class AtmMachine
{
public:
	std::unordered_map<int, int> NotesCount;
	double balance = 0;
	Bank ABC;

	void init();
	int AtmMachine::withdraw(std::string cardNum, double amount);
	int AtmMachine::deposit(std::string cardNum, double amount);
};

