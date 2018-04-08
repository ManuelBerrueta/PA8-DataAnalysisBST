#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <chrono>
#include <thread>

using std::ifstream;
using std::ofstream;
using std::fstream;
using std::string;
using std::ios;
using std::cin;
using std::cout;
using std::endl;
using std::getline;
using std::stoi;

/******************
   Abstract Class
 ******************/

class Node
{
public:
	Node(string &newData);
	//Allows for the outer Node (Transaction Node) to get delted then
	virtual ~Node();

	string getData();
	void setData(string &newData);

	Node *& getmpLeft();
	void setmpLeft(Node *& newNode);

	Node *& getmpRight();
	void setmpRight(Node *& newNode);

	virtual void printData() = 0;

protected:
	string mData;
	Node *mpLeft;
	Node *mpRight;
};