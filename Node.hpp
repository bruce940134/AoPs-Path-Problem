/*

Node Class:

Variables:
    value:       The value of the current node

    leftParent:  A Node pointer pointing to the Node up-left  of the current Node

    rightParent: A Node pointer pointing to the Node up-right of the current Node

    leftChild:   A Node pointer pointing to the Node bottom-left  of the current Node

    rightChild:  A Node pointer pointing to the Node bottom-right of the current Node

    from:        A variable that contains values -1, 0, 1
        -1: Initial value. Means the Node isn't visited
         0: Means the current Node is being visited by the right parent Node.
         1: Means the current Node is being visited by the left  parent Node.

    childrenVisited: A variable that contains values 0, 1, 2
         0: Initial value. Means the current Node hasn't visited any of its child Node/
         1: Means the current Node has visited its left child Node, but hasn't visited its right child Node.
         2: Means the current Node has visited both its left and right child Nodes.

Functions:
    Node(int value): Constructor for creating a Node with the value of value.

    bool isFull():   Returns true if the current Node has a left child Node and a right child Node.

    bool isEmpty():  Returns true if the current Node doesn't have any child (both left and right child are null).
*/


#include <iostream>

using namespace std;

class Node{

public:
    int value;
    Node* leftParent;
    Node* rightParent;
    Node* leftChild;
    Node* rightChild;
    int from;
    int childrenVisited;

    Node(int value){
        this->value = value;
        this->leftParent = nullptr;
        this->rightParent = nullptr;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->from = -1;
        this->childrenVisited = 0;
    }

    bool isFull(){
        if(this->leftChild != nullptr && this->rightChild != nullptr){
            return true;
        }
        return false;
    }

    bool isEmpty(){
        if(this->leftChild == nullptr && this->rightChild == nullptr){
            return true;
        }
        return false;
    }

};