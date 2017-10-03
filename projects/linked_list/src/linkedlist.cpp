#include "linkedlist.h"


struct Node_linkedList
{
    int data;
    Node_linkedList *nextNode;
    Node_linkedList *prevNode;
};


// Class Constructor
LinkedList::LinkedList()
{
    // Initialize the head node to null
    headNode = NULL;
}

// Class Methods

LinkedList::Node_linkedList* LinkedList::create_node(int data)
{
    Node_linkedList *tempNode;
    tempNode = new Node_linkedList;

    // Check to see if tempNode is NULL before assigning data
    if (tempNode == NULL)
    {
        cout<<"Memory not allocated "<<endl;
        return 0;
    }
    else // if Node not null, initialize the data
    {
        tempNode->data = data;
        tempNode->nextNode = NULL;
        tempNode->prevNode = NULL;
        return tempNode;
    }
}



void LinkedList::insertNodeFront(int data)
{
    //cout<<"Enter the value to be inserted: ";
    //cin>>value;

    // temporary Node variables
    LinkedList::Node_linkedList *tempNode;
    LinkedList::Node_linkedList *tempPrevNode;

    // create a node based on the data
    tempNode = create_node(data);

    // check if the head was ever assigned
    if (headNode == NULL)
    {
        headNode            = tempNode; // assign the tempNode as head since none exists
        headNode->prevNode  = NULL;     // headNode prevNode always NULL
        headNode->nextNode  = NULL;     // Only one node currently, nextNode is NULL
    }
    // if head was previously assigned,
    // add new node to front of list
    else
    {
        tempPrevNode            = headNode;     // hold previous headNode
        headNode                = tempNode;     // assign new headNode
        headNode->prevNode      = NULL;         // always assign prevNode as NULL for headNode
        headNode->nextNode      = tempPrevNode; // assign previous headNode to nextNode

        tempPrevNode->prevNode  = headNode;
    }
    cout<<"Method: insertNodeFront() Complete!"<<endl;
}


void LinkedList::insertNodeInPos(int data, int pos)
{

}


void LinkedList::insertNodeBack(int data)
{
    int value;
    //cout<<"Enter the value to be inserted: ";
    //cin>>value;

    // temporary Node variables
    LinkedList::Node_linkedList *tempNode;
    LinkedList::Node_linkedList *tempSearchNode;

    // create a node based on the data
    tempNode = create_node(data);

    // check if the head was ever assigned
    if (headNode == NULL)
    {
        headNode            = tempNode; // assign the tempNode as head since none exists
        headNode->prevNode  = NULL;     // headNode prevNode always NULL
        headNode->nextNode  = NULL;     // Only one node currently, nextNode is NULL
    }
    // if head was previously assigned,
    // add new node to back of list
    else
    {
        // Get the lat node in the list
        tempSearchNode = headNode;
        while(tempSearchNode->nextNode != NULL)
        {
            tempSearchNode = tempSearchNode->nextNode;
        }

        // now that we are at the tail,
        // set tempNode as new tail
        tempSearchNode->nextNode    = tempNode;
        tempNode->prevNode          = tempSearchNode;
        tempNode->nextNode          = NULL; // The nextNode for the tail is always NULL
    }
    cout<<"Method: insertNodeBack() Complete!"<<endl;
}


void LinkedList::deleteNodeInPos(int pos)
{

}


void LinkedList::sortList()
{

}


void LinkedList::searchList()
{

}


void LinkedList::updateList()
{

}


void LinkedList::reverseList()
{

}


void LinkedList::displayList()
{
    int listLength = 0;
    int nodeIndex = 0;
    LinkedList::Node_linkedList *tempNode;

    // Check headNode
    if(headNode == NULL)
    {
        cout << endl << "Linked List is empty!" << endl;
    }
    else
    {
        // print the headNode since it is not NULL
        tempNode = headNode;
        // Print the rest of the nodes in the list
        while(tempNode != NULL)
        {

            cout << endl;
            cout << "Node #" << nodeIndex << " location: " << tempNode << endl;
            cout << "Node #" << nodeIndex << " data: "     << tempNode->data << endl;
            cout << "Node #" << nodeIndex << " prevnode: " << tempNode->prevNode << endl;
            cout << "Node #" << nodeIndex << " nextNode: " << tempNode->nextNode << endl;

            nodeIndex++;    // increment our index counter
            listLength++;   // increment the listLength counter
            tempNode = tempNode->nextNode; // get nextNode
        }
        cout << endl << "Total LinkedList length: " << listLength << endl;
    }
}

