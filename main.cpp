#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Tree.hpp"
using namespace std;

int main(){
    //vector< vector<int> > data;

    ifstream fin;

    fin.open("pyramid_sample_input.txt"); //<------ Input file name here

    //Get target
    string str = "";
    getline(fin, str);
    str = str.substr(8, str.length()-8);
    int target = stoi(str);

    //Get tree
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
                    temp = str.substr(start, str.length()-start);
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

    Tree tree;

    tree.build(data);

    cout << "There is a path: " << tree.DFS(target) << endl;

}