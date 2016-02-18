#pragma once
#include "Account.h"
#include <iostream>
using namespace std;

class BinarySearchTree
{
public:
	BinarySearchTree();
	~BinarySearchTree();
	bool Insert(Account *);
	bool Retrieve(const int &accountNumber, Account* &refToAccountFound) const;
	void Display() const;
	void Empty();
	bool isEmpty() const;

private:
	struct Node
	{
		Account* account;
		Node* right;
		Node* left;
	};
	Node *head;
	void Print(Node *) const;//prints all account in the search
	bool recusiveInsertNode(Account *account, Node* &current);
	bool contains(const int &accID, Account * &ref, Node* ptr) const;
};

