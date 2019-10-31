/*Alexa (Nini) de la Fe
 * Project 6
 * */
#include <iostream>
#include <vector>
#include <cassert>
#include <ctime>
#include "BinaryInsertionSort.h"
#include "LinkedList.h"

using namespace std;

int main() {

    int seed;
    int length;
    cout << "Please enter a seed for the random number generator and a length for the vector: " << endl;
    cin >> seed >> length;
    srand(seed);

    //for (int j = 5; j < 100000; j = j + 100) { //for loop allows for a continuous running of the program to get the times and length for the graph and comparison
    //length=j;

    //declares the vector and instantiates an object of the LinkedList
    vector<int> v(length);
    LinkedList L = LinkedList();

    // generate vector of random integers
    for (int i = 0; i < v.size(); i++) {
        v[i] = rand() % 100;
    }

    // creates a linked list with the same random integers as the vector
    for (int i = 0; i < length; i++) {
        L.append(v[i]);
    }

    //prints out the randomized vector
    cout << "List of unsorted random numbers: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;

    //A check to make sure the lists are the same but not necessary for the program to run
    //cout<< "Linked list randomized"<<endl;
    //L.PrintList();

    // binary insertion sort called and clock functions will allow the time to be tracked
    clock_t start_binaryInsertionSort = clock();
    insertionSort(v, v.size());
    clock_t end_binaryInsertionSort = clock();

    // check if sorted
    for (int i = 1; i < v.size(); i++) {
        assert(v[i - 1] <= v[i]);
    }

    // print out sorted list
    cout << "List after binary insertion sort: " << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << "\t";
    }
    cout << endl;

    // FINISH ME


    // LinkedList insertion sort called and clock functions will allow the time to be tracked
    clock_t start_linkedListInsertionSort = clock();
    L.insertionSort();
    clock_t end_linkedListInsertionSort = clock();

    //Print out sorted linked list
    cout << "List after linked list insertion sort: " << endl;
    L.printList();

    //allows us to see the time in a more readable way
    double elapsed_binaryInsertionSort =
            double(end_binaryInsertionSort - start_binaryInsertionSort) / CLOCKS_PER_SEC;
    double elapsed_linkedListInsertionSort =
            double(end_linkedListInsertionSort - start_linkedListInsertionSort) / CLOCKS_PER_SEC;

    //Outputs length and times for binary search and insertion sort for graphing and comparison
    //cout << length << " " << elapsed_binaryInsertionSort << " " << elapsed_linkedListInsertionSort << endl;

}
//}
