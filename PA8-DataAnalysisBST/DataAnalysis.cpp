#include "DataAnalysis.h"

void DataAnalysis::runAnalysis()
{
	openFile();
	getFileData();
	printDatAnalysis();
}

void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv", std::ios::in);
}

bool DataAnalysis::parseFile(TransactionNode *& dataNode, string &transactionType)
{
	bool notDone = false;
	string tempUnits;
	string tempType;

	if (getline(mCsvStream, tempUnits, ','))
	{
		notDone = true;
		getline(mCsvStream, tempType, ',');
		getline(mCsvStream, transactionType);
		dataNode = new TransactionNode(tempType, std::stoi(tempUnits));
		compareInsert(dataNode, transactionType);
	}
	return notDone;
}

void DataAnalysis::getFileData()
{
	TransactionNode *tempNode;
	string transactionType;
	string garbage;
	getline(mCsvStream, garbage);

	while (parseFile(tempNode, transactionType))
	{
	}

	cout << "==== Sold Products =====" << endl;
	mTreeSold.inOrderTraversal();
	cout << "==== Purchased Products =====" << endl;
	mTreePurchased.inOrderTraversal();
	cout << endl << endl;
}

void DataAnalysis::compareInsert(TransactionNode *& newNode, string &transactionType)
{
	if (transactionType == "Purchased")
	{
		mTreePurchased.insert(newNode->getData(), newNode->getUnits());
	}
	else if (transactionType == "Sold")
	{
		mTreeSold.insert(newNode->getData(), newNode->getUnits());
	}
}

void DataAnalysis::printDatAnalysis()
{
	cout << "==== Data Analysis ====" << endl << endl;
	cout << "==== Least Purchased & Least Sold ====" << endl;
	cout << "Least Purchased" << endl;
	mTreePurchased.findSmallest();
	cout << endl;
	cout << "Least Sold" << endl;
	mTreeSold.findSmallest();
	cout << endl << endl;
	cout << "==== Most Purchased & Most Sold ====" << endl;
	cout << "Most Purchased" << endl;
	mTreePurchased.findLargest();
	cout << endl;
	cout << "Most Sold" << endl;
	mTreeSold.findLargest();
	cout << endl;
}
