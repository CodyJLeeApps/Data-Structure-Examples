/*
 * Created By: Cody Lee
 * Created for: Testing / Utilities
 * Created On: 10/02/2017
 * updated On: 10/02/2017
 *
 * Purpose: This is a test application for creating
 *          and working with linked list data structures
 * */
#include <iostream>
#include "linkedlist.h"

using namespace std;

int main(int argc, char *argv[])
{
    LinkedList linkedList;

    // Create Nodes
    linkedList.insertNodeFront(1);
    linkedList.insertNodeFront(2);
    linkedList.insertNodeBack(3);
    linkedList.insertNodeBack(4);
    linkedList.insertNodeBack(5);

    // Try to create a node outside of bounds
//    linkedList.insertNodeInPos(6, 6);

    // Try to create a node in bounds
    cout << endl << "Before node add:" << endl;
    linkedList.displayList();
    linkedList.insertNodeInPos(6, 1);
    cout << endl << "After node add:" << endl;
    linkedList.displayList();

    // Try to remove a node outside of bounds
//    linkedList.deleteNodeInPos(6);

    // Try to remove a node in bounds
//    cout << endl << "Before node delete:" << endl;
//    linkedList.displayList();
    linkedList.deleteNodeInPos(2);
//    cout << endl << "After node delete:" << endl;
//    linkedList.displayList();
}
