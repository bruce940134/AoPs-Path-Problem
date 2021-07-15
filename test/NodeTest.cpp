/*
 * Unit Test for Node.cpp
 */
#include <iostream>
#include <string>
#include <vector>

#include "../Node.hpp"

using namespace std;

int main(){

    cout << endl;
    cout << "Node Test\n" << endl;

    cout << "Constructor Test + isEmpty() Function Test" << endl;

    Node* node = new Node(5);
    assert(node->value == 5);
    assert(node->isFull() == false);
    assert(node->leftChild == nullptr);
    assert(node->leftParent == nullptr);
    assert(node->isEmpty() == true);
    cout << "isEmpty() Function Test Passed" << endl;
    assert(node->visited == 0);

    cout << "Constructor Test Passed" << endl;

    cout << "isFull() Function Test" << endl;

    Node * node1 = new Node(1);
    Node * node2 = new Node(2);
    node->leftChild = node1;
    node1->rightParent = node;
    node->rightChild = node2;
    node2->leftParent = node;
    assert(node->isFull() == true);
    cout << "isFull() Function Test Passed" << endl;


    cout << endl;
}