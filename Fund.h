#pragma once
#include <string>
#include <vector>
#include "Transactions.h"

using namespace std;

class Fund
{
public:
	Fund();
	Fund(string name);
	~Fund();

	int getBalance() const;
	bool setBalance(int money);
	
	string getFundName() const;
	bool setFundName(string Name);

	void printHisotryFund()const;

	bool addFunds(int moneyIn);
	bool subFunds(int moneyOut);

	bool enoughFundsWithdrawl(int moneyOut)const;
	bool addTransaction(Transactions transaction);

	Fund operator=(const Fund& ref);

private:
	string fundName;
	int balance = 0;
	vector<Transactions> fundHistory;
};

