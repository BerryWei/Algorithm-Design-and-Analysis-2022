#include<iostream>
#include<cstring>

using namespace std;

int main(){


    int arrAA[5];
    arrAA[0]=1;
    arrAA[1]=2;
    arrAA[2]=3;
    arrAA[3]=4;
    arrAA[4]=5;


    memset(arrAA, 0, sizeof(arrAA));
    for (int i=0; i<5;i++)
        cout << arrAA[i] <<"\n";
    
    cout << (arrAA[0] == "0") << endl;
    return 0;

}