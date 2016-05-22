#ifndef SAVENAME_H
#define SAVENAME_H
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
class SaveName {
public:
    SaveName();
    void getFile();
    void setNameList(vector<string> &listName,vector<int> &listID,vector<int> &listScore);
    bool findNamea(vector<string>& );
    int hasName(vector<string> &, string name);
    void addName(string name, int);
    void addNameToDB(string name, int);

    vector<string> getNameList();
    vector<int> getIdList();
    vector<int> getScoreList();

    vector<int> findMaxScore(vector<int> &);
    void bubleSort(vector<int> &data, vector<string> &name);
    void show(vector<int> &,vector<string> &name);

    vector<string> nL;
    vector<int> idL, scL;

};
#endif
