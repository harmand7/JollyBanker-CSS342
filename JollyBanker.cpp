#include "JollyBanker.h"
#include <fstream>
#include <iostream>
#include <sstream>

JollyBanker::JollyBanker()
{
}


JollyBanker::~JollyBanker()
{
}

void JollyBanker::ReadFile(string name)
{//this will create the queue
	ifstream infile(name);
	string line;
	while (getline(infile, line))
	{
		istringstream theLine(line);
		char tranCode;
		theLine >> tranCode;
		if (tranCode == 'O')
		{
			string last, first;
			int id;
			theLine >> last >> first >> id;
			Transactions temp(tranCode, last, first, id);
			transactions.push(temp);
		}
		else if (tranCode == 'D' || tranCode=='W')
		{
			int id, amount;
			theLine >> id >> amount;
			Transactions temp(tranCode, id, amount);
			transactions.push(temp);
		}
		else if (tranCode == 'T')
		{
			int id, amount, transferToID;
			theLine >> id >> amount >> transferToID;
			Transactions temp(tranCode, id, amount, transferToID);
			transactions.push(temp);

		}
		else if (tranCode == 'H')
		{
			int id;
			theLine >> id;
			Transactions temp(tranCode, id);
			transactions.push(temp);
		}
		else
		{
			cout << "Transaction Code not found!" << endl;
		}
	}
}
void JollyBanker::ProcessTransaction()
{
	while (!transactions.empty())
	{
		Transactions temp = transactions.front();
		if (temp.getTransactionType() == 'O')
		{
			Account *account = new Account(temp.getFirstName(), temp.getLastName(), temp.getAccountNumber());
			if (!accountsList.Insert(account))
			{
				cerr << "ERROR: Account: " << temp.getAccountNumber() << " is already open. Transferal refused." << endl;
			}
		}
		else if (temp.getTransactionType() == 'D')
		{
			int FundID = temp.getAccountNumber() % 10;
			int accID = temp.getAccountNumber() / 10;
			Account *acc;
			accountsList.Retrieve(accID, acc);
			acc->addFunds(temp.getAmount(), FundID);
			acc->conductedTransaction(temp, FundID);//add transaction
		}
		else if (temp.getTransactionType() == 'W')
		{
			int FundID = temp.getAccountNumber() % 10;
			int accID = temp.getAccountNumber() / 10;
			Account *acc;
			accountsList.Retrieve(accID, acc);
			if (acc->subFunds(temp.getAmount(), FundID))
			{
				temp.setTransactionSuccess(true);
			}
			else // not enough money transaction success is set to fail
			{
				temp.setTransactionSuccess(false);
				cerr << "ERROR: Not enough funds to withdraw " << temp.getAmount() << " from " << temp.getFirstName()<< " " << temp.getLastName()<<
					" " << acc->getFundName(FundID);
			}
			if (!acc->getIncertCheck())
			{
				acc->conductedTransaction(temp, FundID);
			}
		}
		else if (temp.getTransactionType() == 'T')
		{
			int fromFundID = temp.getAccountNumber() % 10;
			int fromAccID = temp.getAccountNumber() / 10;
			int toFundID = temp.getTransferToAccount() % 10;
			int toAccID = temp.getTransferToAccount() / 10;
			int amount = temp.getAmount();

			Account * from, *to;
			accountsList.Retrieve(fromAccID, from);
			accountsList.Retrieve(toAccID, to);
			if (accountsList.Retrieve(fromAccID, from))
			{
				if (accountsList.Retrieve(toAccID, to))
				{
					if (from->subFunds(amount, fromFundID))
					{
						to->addFunds(amount, toFundID);
						to->conductedTransaction(temp, toFundID);
						from->conductedTransaction(temp, fromFundID);
					}
					else
					{
						cerr << "ERROR: Unsufficent Funds to conduct transfer. From account number: " <<
							from->getAccountNum() << " account: " << from->getFundName(fromFundID) << " to account number: " <<
							to->getAccountNum() << " account: " << to->getFundName(toFundID) << " from the amount of: "
							<< temp.getAmount() << endl;
					}
				}
				else
				{
					cerr << "ERROR: Account: " << toAccID << " not found. Transderal refused" << endl;
				}

			}
			else
			{
				cerr << "ERROR: Account: " << fromAccID << " not found. Transderal refused" << endl;
			}
		}
		else if (temp.getTransactionType() == 'H')
		{
			if (temp.getAccountNumber() >= 10000 && temp.getAccountNumber() <= 99999)
			{
				int fundID = temp.getAccountNumber() % 10;
				int accID = temp.getAccountNumber() / 10;
				Account *account;
				if (accountsList.Retrieve(accID, account))
				{
					cout << "Transaction History For: " << account->getFirstName() << " "
						<< account->getLastName() << " " << endl;
					account->printFundHistory(fundID);
				}
				else
				{
					cerr << "ERROR: Account " << accID << " not found." << endl;
				}
			}
			else if(temp.getAccountNumber() >= 1000 && temp.getAccountNumber() <= 9999)
			{
				Account * account;
				if (accountsList.Retrieve(temp.getAccountNumber(), account))
				{
					cout << "Transaction History For: " << account->getFirstName() << " "
						<< account->getLastName() << " " << endl;
					account->printHistoryAll();
				}
				else
				{
					cerr << "ERROR: Account " << temp.getAccountNumber() << " not found." << endl;
				}
			}
		}
		transactions.pop();
	}
}
void JollyBanker::PrintResults()
{
	cout << "\nProcessing Done. Final Balances" << endl;
	accountsList.Display();
}
