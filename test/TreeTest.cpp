/*
 * Unit Test for Tree.cpp
 */
#include <iostream>
#include <string>
#include <vector>

#include "../Tree.hpp"

using namespace std;

int main(){
    /*
     *  Small Tree Test
     *      1
     *    2   3
     *  4   5   6
     */

    cout << endl;
    cout << "Tree Test\n" << endl;

    vector<int> v1;
    v1.push_back(1);

    vector<int> v2;
    v2.push_back(2);
    v2.push_back(3);

    vector<int> v3;
    v3.push_back(4);
    v3.push_back(5);
    v3.push_back(6);


    vector< vector <int> > data;
    data.push_back(v1);
    data.push_back(v2);
    data.push_back(v3);

    Tree tree;

    cout << "Constructor Test (Empty Tree)" << endl;
    assert(tree.root == nullptr);
    assert(tree.height == 0);

    cout << "Constructor Test Passed" << endl;

    cout << "build() Function Test" << endl;

    tree.build(data);

    assert(tree.height == 3);
    cout << "tree height correct\n";

    Node* curr = tree.root;

    assert(curr->value == 1);
    assert(curr->leftParent == nullptr);
    assert(curr->rightParent == nullptr);
    cout << "1st row correct\n";

    curr = curr->leftChild;

    assert(curr->value == 2);
    assert(curr->rightParent == tree.root);
    assert(curr->leftParent == nullptr);
    assert(curr->rightChild != nullptr);
    assert(curr->leftChild != nullptr);

    curr = curr->rightParent->rightChild;

    assert(curr->value == 3);
    assert(curr->rightParent == nullptr);
    assert(curr->leftParent == tree.root);
    assert(curr->rightChild != nullptr);
    assert(curr->leftChild != nullptr);

    cout << "2nd row correct\n";

    curr = tree.root->leftChild->leftChild;

    assert(curr->value == 4);
    assert(curr->leftParent == nullptr);
    assert(curr->rightParent == tree.root->leftChild);
    assert(curr->leftChild == nullptr);
    assert(curr->rightChild == nullptr);

    curr = curr->rightParent->rightChild;

    assert(curr->value == 5);
    assert(curr->leftParent == tree.root->leftChild);
    assert(curr->rightParent == tree.root->rightChild);
    assert(curr->leftChild == nullptr);
    assert(curr->rightChild == nullptr);

    curr = curr->rightParent->rightChild;

    assert(curr->value == 6);
    assert(curr->leftParent == tree.root->rightChild);
    assert(curr->rightParent == nullptr);
    assert(curr->leftChild == nullptr);
    assert(curr->rightChild == nullptr);

    cout << "3rd row correct\n";

    cout << "build() Function Test Passed" << endl;

    cout << "DFS TEST" << endl;
    assert(tree.DFS(10) == "LR");
    cout << "DFS Test Passed" << endl;

}