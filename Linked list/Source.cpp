#include "Linked_list.h"

int main()
{
	Node<int>* header = nullptr;
	Node<int>* obj1 = nullptr;
	Node<int>* obj2 = nullptr;
	Node<int>* obj3 = nullptr;
	

	header = new Node<int>(1);
	obj1 = new Node<int>(2);
	header->insertAfter(obj1);
	obj2 = new Node<int>(4);
	obj3 = new Node<int>(5);
	obj1->insertAfter(obj3);
	obj1->insertAfter(obj2);

	cout << header->getValue();
	cout << endl;
	cout << obj1->getValue();




}