#ifndef BINARYINSERTIONSORT_LINKEDLIST_H
#define BINARYINSERTIONSORT_LINKEDLIST_H

#include "Node.h"
#include <iostream>

using namespace std;

class LinkedList {
public:
    LinkedList(); //constructor
    //LinkedList(int leng); //alternative constructor
    LinkedList(const LinkedList &list); //copy constructor
    LinkedList& operator= (const LinkedList &assign); //copy assignment operator
    ~LinkedList(); //destructor
    void append(int newNode); //adds functions to a linked list
    void printList(); //prints a linked list
    void insertionSort(); //sorts the linked list

private:
    Node* head;
};

#endif //BINARYINSERTIONSORT_LINKEDLIST_H
