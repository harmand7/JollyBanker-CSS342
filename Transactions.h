#pragma once
#include <string>
using namespace std;

class Transactions
{
	friend ostream & operator<<(ostream &output, const Transactions &transaction);
public:
	//open account takes tracsaction type, last name, first name, account number
	Transactions(char tType, string lastName, string firstName, int account);

	//Deposits 
	//Withdrawls
	Transactions(char tType, int account, int ammount);

	//Transfer
	Transactions(char tType, int account, int ammount, int toAccount);

	//History
	Transactions(char tType, int account);

	~Transactions();

	bool setTransactionType(char tType);
	bool setFirstName(string);
	bool setLastName(string);
	bool setAccountNumber(int);
	bool setAmount(int);
	bool setTransferAccount(int);
	bool setTransactionSuccess(bool statment);

	char getTransactionType()const;
	string getFirstName() const;
	string getLastName() const;
	int getAccountNumber() const;
	int getAmount() const;
	int getTransferToAccount() const;
	bool getTransactionSuccess() const;

private:
	char transactionType;
	int accountNumber, amount, transferAcc;
	string lastName, firstName;
	bool success = false;
};

