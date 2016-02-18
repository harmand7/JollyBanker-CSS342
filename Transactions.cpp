#include "Transactions.h"

//open account takes tracsaction type, last name, first name, account number
Transactions::Transactions(char tType, string lastName, string firstName, int account)
{
	setTransactionType(tType);
	setLastName(lastName);
	setFirstName(firstName);
	setAccountNumber(account);
	setTransactionSuccess(true);
}

//Deposits 
//Withdrawls
Transactions::Transactions(char tType, int account, int amount)
{
	setTransactionType(tType);
	setAccountNumber(account);
	setAmount(amount);
	setTransactionSuccess(true);
}

//Transfer
Transactions::Transactions(char tType, int account, int amount, int toAccount)
{
	setTransactionType(tType);
	setAccountNumber(account);
	setAmount(amount);
	setTransferAccount(toAccount);
	setTransactionSuccess(true);
}

//History
Transactions::Transactions(char tType, int account)
{
	setTransactionType(tType);
	setAccountNumber(account);
	setTransactionSuccess(true);
}

Transactions::~Transactions()
{
}

bool Transactions::setTransactionType(char tType)
{
	transactionType = tType;
	return true;
}

bool Transactions::setFirstName(string FN)
{
	firstName = FN;
	return true;
}

bool Transactions::setLastName(string LN)
{
	lastName = LN;
	return true;
}

bool Transactions::setAccountNumber(int Acc)
{
	accountNumber = Acc;
	return true;
}

bool Transactions::setAmount(int money)
{
	amount = money;
	return true;
}

bool Transactions::setTransferAccount(int TA)
{
	transferAcc = TA;
	return true;
}

bool Transactions::setTransactionSuccess(bool statement)
{
	success = statement;
	return true;
}
char Transactions::getTransactionType()const
{
	return transactionType;
}

string Transactions::getFirstName() const
{
	return firstName;
}
string Transactions::getLastName() const
{
	return lastName;
}
int Transactions::getAccountNumber() const
{
	return accountNumber;
}
int Transactions::getAmount()const
{
	return amount;
}
int Transactions::getTransferToAccount() const
{
	return transferAcc;
}
bool Transactions::getTransactionSuccess() const
{
	return success;
}

ostream& operator<<(ostream &out, const Transactions &refToTransaction)
{
	if (refToTransaction.getTransactionType() == 'D' || refToTransaction.getTransactionType() == 'W')
	{
		out << "  " << refToTransaction.getTransactionType() << " "<<refToTransaction.getAccountNumber() << " " << refToTransaction.getAmount();
	}
	else if(refToTransaction.getTransactionType() == 'T')
	{
		out << "  " << refToTransaction.getTransactionType() << " " << refToTransaction.getAccountNumber() << " " << refToTransaction.getAmount() << " " << refToTransaction.getTransferToAccount();
	}
	if (!refToTransaction.getTransactionSuccess())
	{
		out << " (Failed)";
	}

	return out << endl;
}