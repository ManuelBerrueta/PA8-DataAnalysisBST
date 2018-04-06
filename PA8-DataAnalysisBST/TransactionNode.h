#pragma once

#include "Node.h"

class TransactionNode : public Node
{
public:
	TransactionNode(string &newData, int numUnits);
	~TransactionNode();

	int getUnits();
	void setUnits(int newUnits);

	void printData();

private:
	int mUnits;
};