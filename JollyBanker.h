#include <string>
#include<vector>
#include<queue>
#include "BinarySearchTree.h"
#include "Transactions.h"

using namespace std;
#pragma once
class JollyBanker
{
public:
	JollyBanker();
	~JollyBanker();
	void ReadFile(string name);
	void ProcessTransaction();
	void PrintResults();
private:
	BinarySearchTree accountsList;
	queue<Transactions> transactions;
	
};

