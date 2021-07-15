#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include "Tree.hpp"
using namespace std;

int main(){
    //vector< vector<int> > data;

    ifstream fin;

    fin.open("pyramid_sample_input.txt");

    //Get target
    string str = "";
    getline(fin, str);
    str = str.substr(8, str.length()-7);
    int target = stoi(str);

    //Get tree
    vector< vector <int> > data;
    while(!fin.eof()){
        getline(fin, str);
        vector<int> level;
        int start = 0;
        for(int i = 0; i < str.length(); i++){
            string temp = "";
            if(str[i] == ',' || i == str.length()-1){
                temp = str.substr(start, i-start);
                level.push_back(stoi(temp));
                start = i+1;
            }

            if(start == str.length()-1){
                temp = str.substr(start, 1);
                level.push_back(stoi(temp));
            }
        }
        data.push_back(level);
    }
    fin.close();

    if(data[data.size()-1].size() == 0){
        data.pop_back();
    }

    cout << data.size() << endl;

    Tree tree;

    tree.build(data);

    cout << tree.height << endl;
    cout << target << endl;

    cout << tree.DFS(target) << endl;

}