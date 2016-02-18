
#include <iostream>
#include "Fund.h"

Fund::Fund()
{
	setBalance(0);
}

Fund::Fund(string Name)
{
	setFundName(Name);
	setBalance(0);
}

Fund::~Fund()
{
}


int Fund::getBalance() const
{
	return balance;
}

bool Fund::setBalance(int money)
{
	balance = money;
	return true;
}

string Fund::getFundName() const
{
	return fundName;
}

bool Fund::setFundName(string Name)
{
	fundName = Name;
	return true;
}

void Fund::printHisotryFund() const
{
	if (fundHistory.size() != 0)
	{
		cout << fundName << ": $" << balance << endl;

		for (int i = 0;i < fundHistory.size();i++)
		{
			cout << "  " << fundHistory[i];
		}
	}
}

bool Fund::addFunds(int moneyIn)
{
	balance += moneyIn;
	return true;
}

bool Fund::subFunds(int moneyOut)
{
	if (enoughFundsWithdrawl(moneyOut))
	{
		balance -= moneyOut;
	}
	return true;
}

bool Fund::enoughFundsWithdrawl(int moneyOut) const
{	
	if (balance >= moneyOut)
	{
		return true;
	}
	return false;
}

bool Fund::addTransaction(Transactions transaction)
{
	fundHistory.push_back(transaction);
	return true;
}

Fund Fund::operator=(const Fund & ref)
{
	Fund temp;
	temp.fundHistory = ref.fundHistory;
	temp.fundName = ref.fundName;
	temp.balance = ref.balance;
	return temp;
}

