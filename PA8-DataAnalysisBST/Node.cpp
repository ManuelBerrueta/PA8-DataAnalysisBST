#include "Node.h"

Node::Node(string &newData)
{
	mData = newData;
	mpLeft = nullptr;
	mpRight = nullptr;
}

Node::~Node()
{
}

string Node::getData()
{
	return mData;
}

void Node::setData(string & newData)
{
	mData = newData;
}

Node *& Node::getmpLeft()
{
	return mpLeft;
}

void Node::setmpLeft(Node *& newNode)
{
	mpLeft = newNode;
}

Node *& Node::getmpRight()
{
	return mpRight;
}
void Node::setmpRight(Node *& newNode)
{
	mpRight = newNode;
}
