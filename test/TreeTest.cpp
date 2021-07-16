/*
 * Unit Test for Tree.cpp
 */
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "../Tree.hpp"

using namespace std;

int main(){


    ifstream fin;
    fin.open("small_tree_input.txt");

    string str = "";
    getline(fin, str);
    str = str.substr(8, str.length()-8);
    int target = stoi(str);

    vector< vector <int> > data;

    //First row doesn't have ','
    vector<int> firstRow;
    getline(fin, str);
    firstRow.push_back(stoi(str));
    data.push_back(firstRow);

    while(!fin.eof()){
        getline(fin, str);
        vector<int> level;
        int start = 0;
        for(int i = 0; i < str.length(); i++){
            string temp = "";
            
            if(i == str.length()-1){
                if(start == i){
                    temp = str.substr(start, 1);
                }
                else{
                    temp = str.substr(start, i-start);
                }
                level.push_back(stoi(temp));
            }

            if(str[i] == ','){
                temp = str.substr(start, i-start);
                level.push_back(stoi(temp));
                start = i+1;
            }

        }

        data.push_back(level);
    }
    fin.close();

    if(data[data.size()-1].size() == 0){
        data.pop_back();
    }

    cout << endl;
    cout << "Tree Test\n" << endl;

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
    assert(curr->from == -1);
    assert(curr->isFull() == true);
    assert(curr->isEmpty() == false);
    cout << "1st row correct\n";

    curr = curr->leftChild;

    assert(curr->value == 2);
    assert(curr->rightParent == tree.root);
    assert(curr->leftParent == nullptr);
    assert(curr->rightChild != nullptr);
    assert(curr->leftChild != nullptr);
    assert(curr->from == -1);
    assert(curr->isFull() == true);
    assert(curr->isEmpty() == false);

    curr = curr->rightParent->rightChild;

    assert(curr->value == 3);
    assert(curr->rightParent == nullptr);
    assert(curr->leftParent == tree.root);
    assert(curr->rightChild != nullptr);
    assert(curr->leftChild != nullptr);
    assert(curr->from == -1);
    assert(curr->isFull() == true);
    assert(curr->isEmpty() == false);

    cout << "2nd row correct\n";

    curr = tree.root->leftChild->leftChild;

    assert(curr->value == 4);
    assert(curr->leftParent == nullptr);
    assert(curr->rightParent == tree.root->leftChild);
    assert(curr->leftChild == nullptr);
    assert(curr->rightChild == nullptr);
    assert(curr->from == -1);
    assert(curr->isFull() == false);
    assert(curr->isEmpty() == true);

    curr = curr->rightParent->rightChild;

    assert(curr->value == 1);
    assert(curr->leftParent == tree.root->leftChild);
    assert(curr->rightParent == tree.root->rightChild);
    assert(curr->leftChild == nullptr);
    assert(curr->rightChild == nullptr);
    assert(curr->from == -1);
    assert(curr->isFull() == false);
    assert(curr->isEmpty() == true);

    curr = curr->rightParent->rightChild;

    assert(curr->value == 1);
    assert(curr->leftParent == tree.root->rightChild);
    assert(curr->rightParent == nullptr);
    assert(curr->leftChild == nullptr);
    assert(curr->rightChild == nullptr);
    assert(curr->from == -1);
    assert(curr->isFull() == false);
    assert(curr->isEmpty() == true);

    cout << "3rd row correct\n";

    cout << "build() Function Test Passed" << endl;

    cout << "DFS TEST" << endl;
    assert(tree.DFS(3) == "RL");
    cout << "DFS Test Passed" << endl;

}