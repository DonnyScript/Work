//
//  main.cpp
//  Linked list
//
//  Created by Donovan McCarthy on 7/11/19.
//  Copyright © 2019 Donovan Mccarthy. All rights reserved.
//

#include "Linked_list.h"

int main()
{
    Node<int>* head = nullptr;
    Node<int>* Obj1 = nullptr;
    Node<int>* Obj2 = nullptr;

    head = new Node<int>(2);
    Obj1 = new Node<int>(55);//This is how you declare them, you can also insert into a list 
    head->insertAfter(Obj1);
    Obj2 = new Node<int>(5);
    Obj1->insertAfter(Obj2);
    
    return 0;
}
