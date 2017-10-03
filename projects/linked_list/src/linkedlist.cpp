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

/**
 * @brief LinkedList::create_node
 * @param data
 * @return LinkedList::Node_LinkedList
 * @details The create_node method takes in data to be stored
 *          in the node, and creates the node. The created node
 *          is then returned to the calling function to link to the list.
 */
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

/**
 * @brief LinkedList::get_node
 * @param position
 * @return LinkedList::Node_LinkedList
 */
LinkedList::Node_linkedList* LinkedList::get_node(int position)
{
    int nodeIndex;
    LinkedList::Node_linkedList *tempNode;

    // set tempNode to headNode to begin traversing list
    tempNode = headNode;
    for(nodeIndex = 0; nodeIndex < position; nodeIndex++)
    {
        if(tempNode != NULL)
        {
            tempNode = tempNode->nextNode;
        }
        else
        {
            cout << endl << "Error: can't traverse list to specified node!" << endl;
            return NULL;
        }
    }
    return tempNode;
}


/**
 * @brief LinkedList::insertNodeFront
 * @param data
 * @details The insertNodeFront method takes in data to be stored
 *          in the node, and creates a new headNode. The old headNode
 *          is moved down the list to the next position.
 */
void LinkedList::insertNodeFront(int data)
{
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

/**
 * @brief LinkedList::insertNodeInPos
 * @param data
 * @param pos
 * @details The method insertNodeInPos takes in data to be stored,
 *          and the position in which to store the data. A new node is
 *          created and placed in the position specified. The rest of the
 *          nodes originally in the list are moved down one index to accomodate.
 */
void LinkedList::insertNodeInPos(int data, int pos)
{
    int listLength = getListLength();
    int nodeIndex = 0;
    LinkedList::Node_linkedList *newNode;
    LinkedList::Node_linkedList *tempNode;
    LinkedList::Node_linkedList *tempPrevNode;

    // Check to see if position is outside of the length
    // of the linkedList
    if ( pos > (listLength-1) )
    {
        cout << "Error inserting node at: " << pos << " index out of bounds for this list!" << endl;
    }
    else
    {
        // start at the beginning of the list
        newNode = create_node(data);

        tempNode = headNode;
        for(nodeIndex = 0; nodeIndex <= pos; nodeIndex++)
        {
            if(tempNode != NULL)
            {
                tempNode = tempNode->nextNode;
            }
            else
            {
                cout << endl << "Error: can't traverse list to specified node!" << endl;
            }
        }

        // Grab the current previous node
        tempPrevNode = tempNode->prevNode;

        // Add new node
        newNode->prevNode = tempNode->prevNode;
        newNode->nextNode = tempNode;

        // update the old nodes to connect to the new node
        tempPrevNode->nextNode = newNode;
        tempNode->prevNode = newNode;

        cout << "Node added at index: " << pos << " with data: " << data << endl;
    }
    return;
}

/**
 * @brief LinkedList::insertNodeBack
 * @param data
 * @details The method insertNodeBack takes in data to be stored in node.
 *          A new node is created and placed in the list as the "tail" node.
 *          The old tail node stays in place, but gets its "nextNode"
 *          property updated.
 */
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

/**
 * @brief LinkedList::deleteNodeInPos
 * @param pos
 * @details The method deleteNodeInPos takes in the position of the node
 *          to be removed. The node is deleted, and the nodes following the
 *          node that was deleted are moved up one index to accomodate.
 */
void LinkedList::deleteNodeInPos(int pos)
{
    int listLength = getListLength();
    int nodeIndex = 0;
    LinkedList::Node_linkedList *tempNode;
    LinkedList::Node_linkedList *tempPrevNode;
    LinkedList::Node_linkedList *tempNextNode;

    // Check to see if position is outside of the length
    // of the linkedList
    if ( pos > (listLength-1) )
    {
        cout << "Error deleting node at: " << pos << " index out of bounds for this list!" << endl;
    }
    else
    {
        // start at the beginning of the list
        tempNode = headNode;
        for(nodeIndex = 0; nodeIndex < pos; nodeIndex++)
        {
            if(tempNode != NULL)
            {
                tempNode = tempNode->nextNode;
            }
            else
            {
                cout << endl << "Error: can't traverse list to specified node!" << endl;
            }
        }

        // get a reference to the prev and next nodes
        // this needs to be done before removing node
        tempPrevNode = tempNode->prevNode;
        tempNextNode = tempNode->nextNode;

        // remove node
        tempPrevNode->nextNode = tempNextNode;
        tempNextNode->prevNode = tempPrevNode;
        free(tempNode);
        cout << "Node Removed at index: " << pos << endl;
    }
    return;
}

/**
 * @brief LinkedList::sortList
 * @details The method sortList sorts the linked list based on
 *          the data inside each node. The list is sorted numerically
 *          from smallest to largest.
 */
void LinkedList::sortList()
{

}

/**
 * @brief LinkedList::searchList
 * @param data
 * @return int nodeIndex
 * @details The method searchList takes in data as an integer which is
 *          then used to search through the list. The function returns
 *          the location(s) of nodes that contain the data.
 */
vector<int> LinkedList::searchList(int data)
{
    vector<int> vector_returnNodeIndeces;
    LinkedList::Node_linkedList *tempNode;
    int nodeIndex = 0;

    if(getListLength() > 0)
    {
        tempNode = headNode;
        while(tempNode != NULL)
        {
            if(tempNode->data == data)
            {
                vector_returnNodeIndeces.push_back(nodeIndex);
            }
            nodeIndex++;
            tempNode = tempNode->nextNode;
        }
    }
    else
    {
        cout << "List is empty!";
    }
    return vector_returnNodeIndeces;
}

/**
 * @brief LinkedList::updateList
 * @param data
 * @param pos
 * @details The method updateList takes in an integer
 *          data and position that is used to update the data
 *          within a given node that resides at the specified position.
 */
void LinkedList::updateList(int data, int pos)
{
    int listLength = getListLength();
    LinkedList::Node_linkedList *tempNode;

    // Check to see if position is outside of the length
    // of the linkedList
    if ( pos > (listLength - 1) )
    {
        cout << endl;
        cout << "Error updating node: index out of bounds for this list!" << endl;
        cout << "List has a length of: " << listLength << endl << endl;
    }
    else
    {
        // get the node and update the data
        tempNode = get_node(pos);
        tempNode->data = data;
    }
    cout << "Node updated at index: " << pos << endl;
    return;
}


void LinkedList::reverseList()
{

}

/**
 * @brief LinkedList::displayList
 * @details The method displayList prints the full details
 *          of the linked list. The method prints the location,
 *          data, as well as double link details for each node.
 */
void LinkedList::displayList()
{
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
            tempNode = tempNode->nextNode; // get nextNode
        }
        cout << endl << "Total LinkedList length: " << getListLength() << endl << endl;
    }
}

/**
 * @brief LinkedList::getListLength
 * @return integer representing the
 *         current linked list length.
 * @details The method getListLength() gets the number of nodes
 *          currently residing inside the linked list.
 */
int LinkedList::getListLength() {

    int nodeCount = 0;
    Node_linkedList *tempNode = headNode;

    while(tempNode != NULL)
    {
        nodeCount++;
        tempNode = tempNode->nextNode;
    }
    return nodeCount;
}

