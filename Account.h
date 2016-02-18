#include "Fund.h"
#include "Transactions.h"
#include <vector>
#include <iostream>
#pragma once

class Account
{
public:
	Account(string firstName, string lastName, int AccountID);
	~Account();

	string getFirstName() const;
	string getLastName()const;
	string getFundName(int FundID)const;
	int getFundBalance(int fundID)const;
	bool getIncertCheck()const;
	int getAccountNum()const;
	//string getFundName(int FundID)const;


	void addFunds(int amount, int fundid);
	bool subFunds(int subMoney, int fID);

	void printHistoryAll();
	void printFundHistory(int fID);
	
	void conductedTransaction(Transactions tran, int fID);

	void setFirstName(string Name);
	void setLastName(string Name);
	bool setAmountNum(int accNum);

private:
	string firstName, lastName;
	int accountNum;
	Fund FundArray[10];
	bool insertCheck;
};

