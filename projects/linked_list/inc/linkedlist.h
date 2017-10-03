#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>
#include <iostream>

using namespace std;

class LinkedList
{
public:
    // Structure of the double-linked list
    struct Node_linkedList
    {
        int data = 0;
        Node_linkedList *nextNode = NULL;
        Node_linkedList *prevNode = NULL;
    };
    Node_linkedList *headNode;

    // Default constructor
    LinkedList();

    // Methods for the double LinkedList
    void insertNodeFront(int data);
    void insertNodeInPos(int data, int pos);
    void insertNodeBack(int data);
    void deleteNodeInPos(int pos);
    void sortList();
    vector<int> searchList(int data);
    void updateList(int data, int pos);
    void reverseList();
    void displayList();

protected:

private:
    Node_linkedList* create_node(int value);
    Node_linkedList* get_node(int position);
    int getListLength();
};

#endif // LINKEDLIST_H
