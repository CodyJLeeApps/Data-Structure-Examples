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
    int menuSelection;
    LinkedList linkedList;

    linkedList.insertNodeFront(1);
    linkedList.insertNodeFront(2);
    linkedList.insertNodeBack(3);

    linkedList.displayList();


/*
    cout << "---------------------------------" <<endl;
    cout << " Operations on doubly linked list" <<endl;
    cout << "---------------------------------" <<endl;
    cout << "1.Insert Node at beginning"        <<endl;
    cout << "2.Insert node at last"             <<endl;
    cout << "3.Insert node at position"         <<endl;
    cout << "4.Sort Link List"                  <<endl;
    cout << "5.Delete a Particular Node"        <<endl;
    cout << "6.Update Node Value"               <<endl;
    cout << "7.Search Element"                  <<endl;
    cout << "8.Display Linked List"             <<endl;
    cout << "9.Reverse Linked List "            <<endl;
    cout << "10.Exit "                          <<endl;
    cout << "Enter your choice : ";
    cin >> menuSelection;
    cout << "Value is: " << menuSelection << endl;

    switch(menuSelection)
    {
    case 1:
        cout<<"Inserting Node at Beginning: "<<endl;
        linkedList.insertNodeFront();
        cout<<endl;
        break;
    case 2:
        cout<<"Inserting Node at a given position:: "<<endl;
        linkedList.insertNodeInPos(2);
        cout<<endl;
        break;
    case 3:
        cout<<"Inserting Node at a given position:"<<endl;
        linkedList.insertNodeBack();
        cout<<endl;
        break;
    case 4:
        cout<<"Sort Link List: "<<endl;
        linkedList.sortList();
        cout<<endl;
        break;
    case 5:
        cout<<"Delete a particular node: "<<endl;
        linkedList.deleteNodeInPos(1);
        break;
    case 6:
        cout<<"Update Node Value:"<<endl;
        linkedList.updateList();
        cout<<endl;
        break;
    case 7:
        cout<<"Search element in Link List: "<<endl;
        linkedList.searchList();
        cout<<endl;
        break;
    case 8:
        cout<<"Display elements of link list"<<endl;
        linkedList.displayList();
        cout<<endl;
        break;
    case 9:
        cout<<"Reverse elements of Link List"<<endl;
        linkedList.reverseList();
        cout<<endl;
        break;
    case 0:
        cout<<"Exiting..."<<endl;
        exit(1);
        break;
    default:
        cout<<"Invalid Selection!"<<endl;
    }

    return 0;
*/
}
