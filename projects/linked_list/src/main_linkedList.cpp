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

    linkedList.insertNodeFront(1);
    linkedList.insertNodeFront(2);
    linkedList.insertNodeBack(3);

    linkedList.displayList();
}
