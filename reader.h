#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<char> read(string filepath){
    ifstream inputFile;
    string line;
    char ch;
    vector<char> input;

    inputFile.open(filepath);
    while(inputFile >> noskipws >> ch){
        input.push_back(ch);
    }
    
    return input;
}
