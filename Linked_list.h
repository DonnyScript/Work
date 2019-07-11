#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <iostream> 
using namespace std;

template <typename DynamicType>
class Node
{
private:
    DynamicType value;
    DynamicType* nextValuePtr;
public:
    Node(DynamicType value = 0, DynamicType* nextPtr = nullptr)
    {
        this->value = value;
        this->nextNode = nextPtr;
    }
    void nextNode(Node* nextNode)
    {
        Node* tempPtr = nullptr;

        tempPtr = this->nextValuePtr;
        this->nextValuePtr = nextNode;
        nextNode->nextValuePtr =  tempPtr;
    }
    DynamicType getValue()
    {
        return this->value;
    }
};









#endif