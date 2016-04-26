#include "fio.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

FileIO::FileIO(string name) {
    cout << "create "<< name << ".txt\n";
    addNameToDB(name, 0);
}

void FileIO::addName(string name, int score) {
    string n=name;
    addNameToDB(n, score);
}

void FileIO::addNameToDB(string name,int score) {
    fstream fn("list_name.txt",ios::app);
    cout << nL.size() << "e\n";
    setNameList( nL,idL,scL);
    cout << hasName(nL, name);
    if(hasName(nL, name) == -1) {
        fn << nL.size()+1 << ", " << name << ": "<< score << endl;
    }
    fn.close();
}

void FileIO::setNameList( vector<string> &listName,vector<int> &listID,vector<int> &listScore) {
    string textline;
    fstream fa("list_name.txt");
    int id,score;
    char name[999];
    while(getline(fa, textline)) {
        cout << textline <<"f"<<endl;
        sscanf(textline.c_str(), "%d, %[^:]: %d", &id, name, &score );
        listName.push_back(name);
        listID.push_back(id);
        listScore.push_back(score);
    }
    fa.close();
}

int FileIO::hasName(vector<string> &listName, string name) {
    int f=0,c=0;
    for(int i=0; i<listName.size(); i++) {
        c++;
        if(listName[i].find(name) ==0)f++;
    }
    if(f>0)return c;
    else return -1;
}

vector<int> FileIO::findMaxScore(){
    return sort(getScoreList().begin(),getScoreList().end());
}

vector<string> FileIO::getNameList(){
    return nL;
}

vector<int> FileIO::getIdList(){
    return idL;
}

vector<int> FileIO::getScoreList(){
    return scL;
}
