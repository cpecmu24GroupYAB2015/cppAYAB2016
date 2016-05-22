#include <iostream>
using namespace std;

int main(){
    int **t;
    int x=15;
    int y=16;
    int k=0;
    while(k<10){
        t=new int* [y];
        k++;
        for(int i=0; i< y; i++)
            t[i] = new int [x];

        for(int i=0; i<y; i++){
            for(int j=0 ; j<x; j++){
                t[i][j] = 1;
            }
        }

        for(int i=0; i<y; i++){
            for(int j=0 ; j<x; j++){
                cout << t[i][j];
            }
            cout << endl;
        }

        for(int i=0;i<y;i++)
        delete [] t[i];
        delete []t;

        cout << endl;
        x++;
        y--;

    }
}
