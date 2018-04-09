#include "DataAnalysis.h"

void DataAnalysis::runAnalysis()
{
	getFileData();
	printDatAnalysis();
}

void DataAnalysis::openFile(ifstream & fileDoWork)
{
	fileDoWork.open("data.csv", std::ios::in);
}

bool DataAnalysis::parseFile(ifstream *inFile, TransactionNode *& dataNode)
{
	//TransactionNode * tempNode = nullptr;
	bool done = false;
	string tempUnits;
	string tempType;
	string tempTransaction;
	mCsvStream.open("data.csv", std::ios::in);
	getline(mCsvStream, tempUnits);

	//infile not working
	//getline(*inFile, tempUnits, ',');
	//getline(*inFile, tempType, ',');

	//getline(*inFile, tempTransaction);
	while (getline(mCsvStream, tempUnits, ','))
	{
		getline(mCsvStream, tempType, ',');
		getline(mCsvStream, tempTransaction);
		dataNode = new TransactionNode(tempType, std::stoi(tempUnits));
		compareInsert(dataNode, tempTransaction);
	}


	//change string to int
	//dataNode->setUnits(std::stoi(tempUnits));
	//dataNode->setData(tempType);


	/*
	if (getline)

	else
	bool =false
	
	*/
	
	return done;
}

void DataAnalysis::getFileData()
{
	//Notworking openfile
	//openFile(mCsvStream);
	//TransactionNode TempNode
	TransactionNode *tempNode;


	while (parseFile(&mCsvStream, tempNode)) //This is working, node and data are created
	{
		cout << tempNode->getData();
	}

	mTreeSold.inOrderTraversal();
	mTreePurchased.inOrderTraversal();
	
	//while(parseFile())
}

void DataAnalysis::compareInsert(TransactionNode *& newNode, string transactionType)//This function goes inside parsefile
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
	cout << "Least Purchased" << endl;
	cout << "Type: " << mTreePurchased.findSmallest().getData() << "Units: " << mTreePurchased.findSmallest().getUnits() << endl << endl;
	cout << "Least Sold" << endl;
	cout << "Type: " << mTreeSold.findSmallest().getData() << "Units: " << mTreeSold.findSmallest().getUnits() << endl;
	cout << "Most Purchased" << endl;
	cout << "Type: " << mTreePurchased.findLargest().getData() << "Units: " << mTreePurchased.findLargest().getUnits() << endl << endl;
	cout << "Most Sold" << endl;
	cout << "Type: " << mTreeSold.findLargest().getData() << "Units: " << mTreeSold.findLargest().getUnits() << endl;

}
