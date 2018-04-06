#include "DataAnalysis.h"

void DataAnalysis::openFile()
{
	mCsvSTream.open("data.csv", ios::in);

}

bool DataAnalysis::parseFile(ifstream inFile)
{
	bool done = false;
	string tempUnits;
	string tempType;
	string tempTransaction;

	getline(inFile, tempUnits, ',');
	getline(inFile, tempType, ',');
	getline(inFile, tempTransaction, ',');

	return done;
}

void DataAnalysis::getFileData()
{
	//while(parseFile())
}
