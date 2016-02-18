#include "JollyBanker.h"

int main()
{
	JollyBanker banker;
	banker.ReadFile("BankTransIn.txt");
	banker.ProcessTransaction();
	banker.PrintResults();
	return 0;
}