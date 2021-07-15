#include <iostream>

using namespace std;

class Node{

public:
    int value;
    Node* leftParent;
    Node* rightParent;
    Node* leftChild;
    Node* rightChild;
    int visited;

    Node(int value){
        this->value = value;
        this->leftParent = nullptr;
        this->rightParent = nullptr;
        this->leftChild = nullptr;
        this->rightChild = nullptr;
        this->visited = 0;
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