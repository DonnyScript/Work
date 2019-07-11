#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream> 
using namespace std;

template <typename DynamicType> //As up 7/11/19 it has been tested
class Node
{
private:
    DynamicType value;
    Node<DynamicType>* nextNodePtr;
public:

    Node(DynamicType value = 0, Node* nextPtr = nullptr)
    {
        this->value = value;
        this->nextNodePtr = nextPtr;
    }

    void insertAfter(Node* nextNode)
    {
        Node* tempPtr = nullptr;

        tempPtr = this->nextNodePtr;
        this->nextNodePtr = nextNode;
        nextNode->nextNodePtr =  tempPtr;
    }

    DynamicType getValue()
    {
        return this->value;
    }

	DynamicType getNextNodePtr()
	{
		return this->nextNodePtr;
	}

	DynamicType printNodeValue()
	{
		return this->value;
	}
};

#endif