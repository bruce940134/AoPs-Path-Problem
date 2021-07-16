/*

Tree Class:

Variables:
    root:   A Node pointer that points to the root of the tree (the Node at the top).

    height: A variable that stores the height of the tree (how many rows there are).

Functions:

    Tree(): Constructor for creating an empty Tree.

    ~Tree(): Destructor to delete a tree object when the program ends.

    void build(vector< vector<int> > data): A function to build the tree based on the data.
    (data is a 2D vector that stores the given values row by row)

    string DFS(int target): Perform DFS on the tree to find a path starting from the root to the last row of the tree, where
                            target equals the multiplication of the values of the Nodes in the path.

    void deleteAll(Node* ptr): Helper function for the destructor to delete all of the Nodes.
*/
#include <iostream>
#include <vector>
#include "Node.hpp"

using namespace std;

class Tree{

public:
    Node* root;
    int height;

    Tree(){
        this->root = nullptr;
        this->height = 0;
    }

    ~Tree(){
        deleteAll(root);
    }

    void build(vector< vector<int> > data){

        for(int i = 0; i < data.size(); i++){
            vector<int> row = data[i];

            //First row
            if(i == 0){
                Node* node = new Node(row[0]);
                this->root = node;
            }
            //Second row
            else if(i == 1){
                Node* leftNode = new Node(row[0]);
                Node* rightNode = new Node(row[1]);
                root->leftChild = leftNode;
                leftNode->rightParent = root;
                root->rightChild = rightNode;
                rightNode->leftParent = root;
            }
            //other rows
            else{
                Node* ptr = root;
                while(ptr->leftChild != nullptr){
                    ptr = ptr->leftChild;
                }

                for(int j = 0; j < row.size(); j++){
                    //Check if node at ptr is full (has left and right children)
                    if(ptr->isFull()){
                        ptr = ptr->rightParent->rightChild;
                    }

                    Node* node = new Node(row[j]);
                    //If on the sides will have one less parent
                    if(j == 0){
                        ptr->leftChild = node;
                        node->rightParent = ptr;
                    }
                    else if(j == row.size()-1){
                        ptr->rightChild = node;
                        node->leftParent = ptr;
                    }
                    else{
                        ptr->rightChild = node;
                        node->leftParent = ptr;
                        ptr = ptr->rightParent->rightChild;
                        ptr->leftChild = node;
                        node->rightParent = ptr;
                    }
                }
            }

            height++;
        }
    }

    string DFS(int target){
        Node* curr = this->root;
        target = target / curr->value;
        string path = "";

        while(true){

            //At the last row, check if the path is valid
            if(curr->isEmpty()){
                if(target == 1){
                    break;
                }
                else{
                    target = target * curr->value;
                    if(curr->from == 0){
                        curr->from = -1;
                        curr = curr->rightParent;
                    }
                    else{
                        curr->from = -1;
                        curr = curr->leftParent;
                    }
                    continue;
                }
            }

            //If a child isn't visited and there's a path, take it
            //Else, go back to the parent curr came from
            if((curr->childrenVisited < 1) && (target % curr->leftChild->value == 0)){
                curr->childrenVisited = 1;
                curr = curr->leftChild;
                curr->from = 0;
                target = target / curr->value;
                continue;
            }
            else if((curr->childrenVisited < 2) && (target % curr->rightChild->value == 0)){
                curr->childrenVisited = 2;
                curr = curr->rightChild;
                curr->from = 1;
                target = target / curr->value;
                continue;
            }
            else{
                target = target * curr->value;
                curr->childrenVisited = 0;
                if(curr->from == 0){
                    curr->from = -1;
                    curr = curr->rightParent;
                }
                else{
                    curr->from = -1;
                    curr = curr->leftParent;
                continue;
                }
            }
        }
        
        //Found a path, retrace to get the path
        while(curr != root){
            if(curr->from == 0){
                curr = curr->rightParent;
                path = 'L' + path;
            }
            else{
                curr = curr->leftParent;
                path = 'R' + path;
            }
        }

        return path;
    }


    void deleteAll(Node* ptr){
        if(ptr == nullptr){
            return;
        }

        if(ptr->leftChild != nullptr){
            deleteAll(ptr->leftChild);
        }
        if(ptr->rightChild != nullptr){
            if(ptr->rightChild->rightParent != nullptr){
                ptr->rightChild->rightParent->leftChild = nullptr;
            }
            deleteAll(ptr->rightChild);
        }

        delete ptr;
    }
};