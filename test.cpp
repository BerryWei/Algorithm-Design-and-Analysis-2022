#include<iostream>
#include<math.h>
using namespace std;

int count(int n)
{
    double num1  = floor(log2(n));
    int num2 = 2*pow(2, num1) + 2 * pow(2, num1) * num1;
    // 
    int num3 = (n - pow(2, num1)) *(6 + 2*(num1 ) ) ;
    return num3 + num2;
}


int main(){
    cout << count(2) << endl;
    cout << count(3) << endl;
    cout << count(4) << endl;
    cout << count(5) << endl;
    cout << count(6) << endl;
    cout << count(7) << endl;
    cout << count(8) << endl;
    cout << floor(log2(3)) << endl;
    return 0;
}