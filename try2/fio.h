#ifndef FILEIO_H
#define FILEIO_H
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
class FileIO {
public:
    FileIO(string name);
    void getFile();
    void setNameList(vector<string> &listName,vector<int> &listID,vector<int> &listScore);
    bool findNamea(vector<string>& );
    int hasName(vector<string> &, string name);
    void addName(string name, int);
    void addNameToDB(string name, int);

    vector<string> getNameList();
    vector<int> getIdList();
    vector<int> getScoreList();

    vector<int> findMaxScore();

private:
    vector<string> nL;
    vector<int> idL, scL;

};
#endif
