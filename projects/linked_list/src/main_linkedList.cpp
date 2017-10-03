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

    // Try to create a node
    linkedList.insertNodeInPos(6, 1); // in-bounds
    linkedList.insertNodeInPos(6, 4); // on last node
    linkedList.insertNodeInPos(6, 7); // out-of-bounds

    // Try to remove a node
    linkedList.deleteNodeInPos(1);  // in-bounds
    linkedList.deleteNodeInPos(4);  // on last node
    linkedList.deleteNodeInPos(5);  // out-of-bounds

    // print linked list
    linkedList.displayList();

    // Try to update a node
    linkedList.updateList(3, 4); // last node

    linkedList.displayList();

    vector<int> vect_test = linkedList.searchList(3);
    if(vect_test.size() > 0)
    {
        cout << "Data located in location(s): ";
        for(int index : vect_test)
        {
            cout << index << ", ";
        }
        cout << endl;
    }
    else
    {
        cout << "Data not present in list!";
    }


    return(0);
}
