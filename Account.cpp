#include "Account.h"

Account::Account(string fName, string lName, int AccID)
{
	insertCheck = false;
	firstName = fName;
	lastName = lName;
	accountNum = AccID;
	string fundNames[] = { "Money Market", "Prime Money Market", 
		"Long-Term Bond", "Short-Term Bond", 
		"500 Index Fund", "Capital Value Fund",
		"Growth Equity Fund", "Growth Index Fund", 
		"Value Fund", "Value Stock Index" };
	for (int i = 0; i < 10;i++)
	{
		FundArray[i].setFundName(fundNames[i]);
		FundArray[i].setBalance(0);
	}
}

string Account::getFirstName()const
{
	return firstName;
}

string Account::getLastName()const
{
	return lastName;
}

string Account::getFundName(int FundID)const
{
	return FundArray[FundID].getFundName();
}

int Account::getFundBalance(int FundID)const
{
	return FundArray[FundID].getBalance();
}

bool Account::getIncertCheck()const
{
	return insertCheck;
}

int Account::getAccountNum()const
{
	return accountNum;
}

void Account::setFirstName(string Name)
{
	firstName = Name;
}

void Account::setLastName(string Name)
{
	lastName = Name;
}

bool Account::setAmountNum(int accNum)
{
	accountNum = accNum;
	return true;
}
void Account::addFunds(int addMoney, int fid)
{
	FundArray[fid].addFunds(addMoney);
}
bool Account::subFunds(int subMoney, int fid)
{
	if (FundArray[fid].enoughFundsWithdrawl(subMoney))
	{
		FundArray[fid].subFunds(subMoney);
		return true;
	}
	if (fid >= 0 && fid <= 3)
	{
		if (fid == 0)
		{
			if (FundArray[fid].getBalance() + FundArray[1].getBalance() >= subMoney)
			{
				int leftOverBanlance = subMoney - FundArray[fid].getBalance();
				FundArray[fid].subFunds(subMoney-leftOverBanlance);
				FundArray[1].subFunds(leftOverBanlance);
				Transactions* first = new Transactions('W', accountNum * 10 + fid, subMoney - leftOverBanlance);
				Transactions* secound = new Transactions('W', accountNum * 10 + (1), leftOverBanlance);
				FundArray[fid].addTransaction(*first);
				FundArray[1].addTransaction(*secound);
				insertCheck = true;
				return true;
			}
		}
		else if (fid == 1)
		{
			if (FundArray[fid].getBalance() + FundArray[0].getBalance() >= subMoney)
			{
				int leftOverBanlance = subMoney - FundArray[fid].getBalance();
				FundArray[fid].subFunds(subMoney - leftOverBanlance);
				FundArray[0].subFunds(leftOverBanlance);
				Transactions* first = new Transactions('W', accountNum * 10 + fid, subMoney - leftOverBanlance);
				Transactions* secound = new Transactions('W', accountNum * 10 + (0), leftOverBanlance);
				FundArray[fid].addTransaction(*first);
				FundArray[0].addTransaction(*secound);
				insertCheck = true;
				return true;
			}
		}
		else if (fid == 2)
		{
			if (FundArray[fid].getBalance() + FundArray[fid + 1].getBalance() >= subMoney)
			{
				int leftOverBanlance = subMoney - FundArray[fid].getBalance();
				FundArray[fid].subFunds(subMoney - leftOverBanlance);
				FundArray[3].subFunds(leftOverBanlance);
				Transactions* first = new Transactions('W', accountNum * 10 + fid, subMoney - leftOverBanlance);
				Transactions* secound = new Transactions('W', accountNum * 10 + (3), leftOverBanlance);
				FundArray[fid].addTransaction(*first);
				FundArray[3].addTransaction(*secound);
				insertCheck = true;
				return true;
			}
		}
		else if (fid == 3)
		{
			if (FundArray[fid].getBalance() + FundArray[fid - 1].getBalance() >= subMoney)
			{
				int leftOverBanlance = subMoney - FundArray[fid].getBalance();
				FundArray[fid].subFunds(subMoney - leftOverBanlance);
				FundArray[2].subFunds(leftOverBanlance);
				Transactions* first = new Transactions('W', accountNum * 10 + fid, subMoney - leftOverBanlance);
				Transactions* secound = new Transactions('W', accountNum * 10 + (2), leftOverBanlance);
				FundArray[fid].addTransaction(*first);
				FundArray[2].addTransaction(*secound);
				insertCheck = true;
				return true;
			}
		}
	}
	else
	{
		
		return false;
	}
}
void Account::printHistoryAll()
{
	for (int i = 0; i < 10; i++)
	{
		FundArray[i].printHisotryFund();
	}
}
void Account::printFundHistory(int fID)
{
	FundArray[fID].printHisotryFund();
}
void Account::conductedTransaction(Transactions tran, int fID)
{
	FundArray[fID].addTransaction(tran);
}
Account::~Account()
{

}