#include "LinkedList.h"
#include "Node.h"
#include <iostream>
using namespace std;

//Constructor method- initializes the private variables
// follows the code from the slides
LinkedList::LinkedList() {
   //cout << "Constructor called" << endl;
    head = nullptr;
}
/*
//did not work how i was expecting it to work
//Alternative Constructor- creates a linked list filled with random numbers based off the length the user enters in main
LinkedList::LinkedList(int leng) {
    cout<<"Alternative constructor called"<<endl;
    head=new Node(rand()%100);
    Node* current=head;
    for (int i = 0; i < leng-1; i++) {
        //cout << "Adding a node..." << endl;
        current->next= new Node(rand()%100);
        current=current->next;
    }
    cout<<"Unsorted Linked List: "<<endl;
    printList();
} */

//copy constructor method- creates a deep copy of the instance
LinkedList::LinkedList(const LinkedList &list) {
    //cout << "Copy constructor called" << endl;
    Node* current = list.head;
    Node* copy = head;
    while (current->next != nullptr){
        copy->next = new Node(current->next->value);
        copy = copy->next;
        current = current->next;
    }
}
//Copy assignment operator- overloads the = operator
LinkedList& LinkedList::operator=(const LinkedList &assign) {
    //cout << "Copy assignment operator called" << endl;
    LinkedList copy;
    swap(copy.head, head);

    return *this;
}

//Destructor- deletes the linked list correctly(?) to avoid memory leakage
LinkedList::~LinkedList() {
    //cout << "Destructor called" << endl;
    Node* curr = head;
    Node* afterCurr = curr->next;

    //iterates until curr->next is nullptr to be able to reach the entire list then deletes curr and moves
    // onto the next element in the linked list
    while(curr->next != nullptr){
        delete(curr);
        curr = afterCurr;
        afterCurr = afterCurr->next;
    }

}

//Adds an item to the head if  head == nullptr or to the end of the linked list
// follows the code from the slides
void LinkedList::append(int newNode) {
    //cout << "Append called" << endl;
    //adds a head if head == nullptr
    if (head == nullptr){
        head = new Node(newNode);
    }
        //adds a node to the node after the head
    else {
        Node* cursor = head;
        while (cursor -> next != nullptr){
            cursor = cursor -> next;
        }
        cursor -> next = new Node (newNode);
    }
}

//Prints a message stating there is an empty linked list or prints out the linked list
// follows the code from the slides
void LinkedList::printList() {
    //cout << "PrintList called" << endl;
    Node* cursor = head;
    //if there is no head then prints a statement saying there are no items
    if (!cursor) {
        cout << "There are no items in your list!" << endl;
    }
        //else it prints a node until there is no nodes left
    else{
        while(cursor){
            cout << cursor->value << "\t";
            cursor = cursor->next;
        }
    }
    cout << endl;
}

//Sorts the linked list to be in increasing order, created in attempt to follow the psuedocode given the description
void LinkedList::insertionSort() {
    //cout << "Sort called" << endl;
    Node* temp;
    Node* previous = head;
    Node* curr = head->next;

    //returns automatically if the linked list size is 0 or 1 because it is already sorted
    if (head->next == nullptr || head == nullptr){
        return;
    }
    //while loop- goes through the entire linked list
    while (curr != nullptr){
        //if statement- checks to see if the current is >= than the previous therefore no sorting needing to occur
        // the nodes are moved up to the next nodes
        if(curr->value >= previous->value){
            previous = previous->next;
            curr = curr->next;
        }
            //else statement- entered if the current is < than the previous
        else {
            //if statement- checks to see if the current is < than the head and if it is moves the node to be the head pointer
            if(curr->value < head->value){
                previous->next = curr->next;
                curr->next = nullptr;
                curr->next = head;
                head = curr;
            }
                //else statement- entered when current is > than the head and the node needs to find its correct location in the list
            else{
                temp = head;
                //while loop- loops through when curr is > the value after temp && when temp is not the last value in the linked list
                // then moves temp to the next mode
                while (curr->value > temp->next->value && temp->next != nullptr){
                    temp = temp->next;
                }
                //moves the nodes to the correct locations and disconnects the pointers that are no longer necessary
                previous->next = curr->next;
                curr->next = nullptr;
                curr->next = temp->next;
                temp->next = curr;
            }
        }
        //moves current
        curr = previous->next;
    }
}


