#include "TransactionNode.h"

TransactionNode::TransactionNode(string &newData, int numUnits) : Node(newData)
{
	this->mUnits = numUnits;
}

TransactionNode::~TransactionNode()
{
}

int TransactionNode::getUnits()
{
	return mUnits;
}

void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

void TransactionNode::printData()
{
	cout << "Units: " << this->mUnits << endl;
	cout << "Data: " << this->mData << endl;
}
