#include "saveName.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include "cls.h"
using namespace std;

SaveName::SaveName() {
    cout << "\ncreate Database Success!\n";
    setNameList(nL,idL,scL);
    cout << "Inititalize Complete\n";
    cls();
}

void SaveName::addName(string name, int score) {
    string n=name;
    addNameToDB(n, score);
}

void SaveName::addNameToDB(string name,int score) {
    fstream fn("list_name.txt",ios::app);
    cout << "NameList Size : "<< nL.size() << "\n";
    setNameList( nL,idL,scL);
    cout << "Last ID : " << hasName(nL, name) << endl;

    if(hasName(nL, name) == -1) {
        fn << 1 << ", " << name << ": "<< score << endl;
    }
    fn.close();
}

void SaveName::setNameList( vector<string> &listName,vector<int> &listID,vector<int> &listScore) {
    string textline;
    fstream fa("list_name.txt");
    int id,score;
    char name[999];
    while(getline(fa, textline)) {
        cout << textline <<endl;
        sscanf(textline.c_str(), "%d, %[^:]: %d", &id, name, &score );
        listName.push_back(name);
        listID.push_back(id);
        listScore.push_back(score);
    }
    fa.close();
}

int SaveName::hasName(vector<string> &listName, string name) {
    int f=0,c=0;
    for(int i=0; i<listName.size(); i++) {
        c++;
        if(listName[i].find(name) ==0)f++;
    }
    if(f>0)return c;
    else return -1;
}


void SaveName::bubleSort(vector<int> &score, vector<string> &name) {
int n = score.size();
    for (int c = 0 ; c < ( n - 1 ); c++) {
        for (int d = 0 ; d < n - c - 1; d++) {
            if (score[d] < score[d+1]) { /* For decreasing order use < */
                swap(score[d],score[d+1]);
                swap(name[d],name[d+1]);
            }
        }
    }
}


void SaveName::show(vector<int> &data, vector<string> &name){
    cout << "\nShow List Data\n";
    for(int i=0; i<data.size();i++){
        cout << data[i] << " " << name[i] <<"\n";
    }
}

bool moreThan (int i,int j) { return (i>j); }


vector<int> SaveName::findMaxScore(vector<int> &data)  {
    sort(data.begin(),data.begin()+6,moreThan);
}


vector<string> SaveName::getNameList() {
    return nL;
}

vector<int> SaveName::getIdList() {
    return idL;
}

vector<int> SaveName::getScoreList() {
    return scL;
}
