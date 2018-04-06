#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{
	destroyTree(mpRoot);
}

Node *& BST::getmpRoot()
{
	return this->mpRoot;
}

void BST::setmpRoot(Node *& newNode)
{
	mpRoot = newNode;
}

void BST::insert(string newData, int newUnits)
{
	insert(mpRoot, newData, newUnits);
}

void BST::inOrderTraversal()
{
	inOrderTraversal(mpRoot);
}

void BST::destroyTree(Node * pTree)
{
	//PostOrder traversal delete function
	if (pTree == nullptr) {
		return;
	}
	else {
		destroyTree(pTree->getmpLeft());
		destroyTree(pTree->getmpRight());
		delete pTree;
	}
}

void BST::insert(Node *& pTree, string newData, int newUnits)
{
	//recursive insert function
	//allocates dynamically a transaction node based on mUnits
	if (pTree == nullptr)
	{
		pTree = new TransactionNode(newData, newUnits);
	}
	else if (newUnits < (dynamic_cast <TransactionNode *>(pTree))->getUnits())
	{
		insert(pTree->getmpLeft(), newData, newUnits);
	}
	else if (newUnits >(dynamic_cast <TransactionNode *>(pTree))->getUnits())
	{
		insert(pTree->getmpRight(), newData, newUnits);
	}
	else
	{
		//cout << "Duplicate Ignored" << endl;
	}

}

void BST::inOrderTraversal(Node *& pTree)
{
	if (pTree == nullptr)
	{
		return;
	}
	else
	{
		inOrderTraversal(pTree->getmpLeft());
		pTree->printData();
		cout << endl;
		inOrderTraversal(pTree->getmpRight());
	}
}
