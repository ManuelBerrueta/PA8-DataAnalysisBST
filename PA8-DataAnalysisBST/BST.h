#pragma once

#include "TransactionNode.h"

class BST
{
public:
	BST();
	~BST();
	Node *& getmpRoot();
	void setmpRoot(Node *& newNode);
	void insert(string newData, int newUnits);
	void inOrderTraversal();
	TransactionNode & findSmallest();
	TransactionNode & findLargest();

private:
	Node * mpRoot;
	void destroyTree(Node *pTree);
	void insert(Node *& pTree, string newData, int newUnits);
	void inOrderTraversal(Node *& pTree);
};