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
                node->visited = 1;
                this->root = node;
            }
            //Second row
            else if(i == 1){
                Node* leftNode = new Node(row[0]);
                leftNode->visited = 1;
                Node* rightNode = new Node(row[1]);
                rightNode->visited = 1;
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
                        node->visited = 1;
                        ptr->leftChild = node;
                        node->rightParent = ptr;
                    }
                    else if(j == row.size()-1){
                        node->visited = 1;
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
        string path = "";

        while(true){
            target = target / curr->value;
            curr->visited += 1;

            //At the last row, check if the path is valid
            if(curr->isEmpty()){
                if(target == 1){
                    break;
                }
                else{
                    target = target * curr->value;
                    path.erase(path.end()-1);
                    if(curr->visited == 2 && curr->rightParent != nullptr){
                        curr = curr->rightParent;
                    }
                    else{
                        curr = curr->leftParent;
                    }
                    continue;
                }
            }

            if(target % curr->leftChild->value == 0 && curr->leftChild->visited != 2){
                curr = curr->leftChild;
                path = path + "L";
                continue;
            }
            else if(target % curr->rightChild->value == 0 && curr->rightChild->visited != 2){
                curr = curr->rightChild;
                path = path + "R";
                continue;
            }
            else{
                target = target * curr->value;
                path.erase(path.end()-1);
                if(curr->visited == 2 && curr->rightParent != nullptr){
                    curr = curr->rightParent;
                }
                else{
                    curr = curr->leftParent;
                }
                continue;
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