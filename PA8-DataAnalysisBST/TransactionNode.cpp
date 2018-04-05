#include "TransactionNode.h"

TransactionNode::TransactionNode(string &newData, int numUnits) : Node(newData)
{
	
	//this->setData(newData);
	this->mUnits = numUnits;
}
