#include "BinarySearchTree.h"

BinarySearchTree::BinarySearchTree()
{
	head = NULL;
}
bool BinarySearchTree::recusiveInsertNode(Account* acc, Node* &cur)
{
	if(cur == NULL)
	{
		cur = new Node();
		cur->account = acc;
		cur->left = NULL;
		cur ->right = NULL;
		return true;
	}
	else
	{
		if (cur->account->getAccountNum() > acc->getAccountNum())
		{
			if (cur->left == NULL)
			{
				Node* temp = new Node();
				temp->account = acc;
				temp->left = NULL;
				temp->right = NULL;
				cur->left = temp;
				return true;
			}
			else
			{
				return recusiveInsertNode(acc, cur->left);
			}
		}
		else if(cur->account->getAccountNum() < acc->getAccountNum())
		{
			if (cur->right == NULL)
			{
				Node* temp = new Node();
				temp->account = acc;
				temp->left = NULL;
				temp->right = NULL;
				cur->right = temp;
				return true;
			}
			else
			{
				return recusiveInsertNode(acc, cur->right);
			}
		}
		else//checks for equilance
		{
			return false;
		}
	}
}
bool BinarySearchTree::Insert(Account* acc)
{
	return recusiveInsertNode(acc,head);
}
bool BinarySearchTree::Retrieve(const int & accountNumber, Account *& refToAccountFound) const
{
	if (head == NULL)
	{
		return false;
	}
		return contains(accountNumber, refToAccountFound, head);
}
void BinarySearchTree::Display() const
{
	if (head != NULL)
	{
		Print(head);
	}
}
void BinarySearchTree::Empty()
{
	delete head;
	head = NULL;
}
bool BinarySearchTree::isEmpty() const
{
	return (head == NULL);
}
void BinarySearchTree::Print(Node *ptr) const
{
	if (ptr != NULL)
	{
		Print(ptr->left);
		cout << ptr->account->getFirstName() << " " << ptr->account->getLastName()
			<< " Account ID: " << ptr->account->getAccountNum() << endl;
		for (int i = 0; i < 10;i++)
		{
			cout << "   " << ptr->account->getFundName(i) << ": $" << ptr->account->getFundBalance(i) << endl;
		}
		cout << endl;
		Print(ptr->right);
	}
}
BinarySearchTree::~BinarySearchTree()
{

}
bool BinarySearchTree::contains(const int &accID, Account * &ref, Node* ptr) const
{
	if (ptr == NULL)
	{
		ref = NULL;
		return false;
	}
	else if (accID == ptr->account->getAccountNum())
	{
		ref = ptr->account;
		return true;
	}
	else if (accID < ptr->account->getAccountNum())
	{
		return contains(accID, ref, ptr->left);
	}
	else
	{
		return contains(accID, ref, ptr->right);
	}
}