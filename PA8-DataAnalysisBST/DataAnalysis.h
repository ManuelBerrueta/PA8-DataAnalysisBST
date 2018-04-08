#pragma once

#include "BST.h"

class DataAnalysis
{
public:
	void runAnalysis();

private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvSTream;
	void openFile(); 
	TransactionNode *& parseFile(ifstream inFile);//nested inside above
	void getFileData(); //nested inside openfile and parsefile nested inside getFile
						//function that loops until all lines are read from the file; 
						//calls the function below, and then displays the current contents of both BSTs;
						//use inOrderTraversal () to display the trees
	void compareInsert(TransactionNode *& newNode);
	void printDatAnalysis();
};