#include "DataAnalysis.h"

void DataAnalysis::openFile()
{
	mCsvSTream.open("data.csv", ios::in);


}

TransactionNode *& DataAnalysis::parseFile(ifstream inFile)
{
	TransactionNode * tempNode = nullptr;
	bool done = false;
	string tempUnits;
	string tempType;
	string tempTransaction;

	getline(inFile, tempUnits, ',');
	//change string to int
	tempNode->setUnits(std::stoi(tempUnits));
	getline(inFile, tempType, ',');
	tempNode->setData(tempType);
	getline(inFile, tempTransaction);

	return tempNode;
}

void DataAnalysis::getFileData()
{
	//TransactionNode TempNode

		//parsefile

	
	//while(parseFile())
}
