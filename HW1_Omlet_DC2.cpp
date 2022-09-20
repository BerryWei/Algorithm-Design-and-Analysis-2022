#include <iostream>
#include <math.h>

using namespace std;

int count(int n)
{
    int num1  = floor(log2(n));
    int num2 = 2*pow(2, num1) + 2 * pow(2, num1) * num1;
    // 
    int num3 = (n - pow(2, num1)) *(6 + 2*(num1 ) ) ;
    return num3 + num2;
}



void OmletDC(int low, int high)
{
    int n = high - low + 1;
    // take photo 1
    if (low == high)
    {
        
        cout << "PHOTO" << endl;
        return;
    }
    if (high < low)
    {
        cout << "PHOTO" << endl;
        return;
    }
    
    
    int mid = (high+low)/2;
    // Start to take photo 2~n
    OmletDC(low, mid);
    for (int i = 0; i < n; i++)
    {
        cout << "POP" << endl;
    }
    // place upper half
    for (int i = low; i <= mid; i++)
    {
        cout << "PLACE " << i << endl;
    }
    // place lower half
    for (int i = high; i >= mid + 1; i--)
    {
        cout << "PLACE " << i << endl;
    }
    
    OmletDC(mid+1, high);

    return;
}

int main()
{
    // init. INPUT
    int n;

    cin >> n;



    cout << count(n) << endl;

    for(int i=1; i<=n ;i++)
    {
        cout << "PLACE " << n - i + 1 << endl;
    }



    OmletDC(1, n);

    return 0;
}