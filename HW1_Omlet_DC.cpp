#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

void OmletDC(int *Arr, int n)
{

    if (n == 1)
    {
        cout << "PLACE 1" << endl;
        cout << "PHOTO" << endl;
        return;
    }

    cout << "PLACE " << n << endl;
    OmletDC(Arr, n - 1);
    // pop out n times
    for (int i = 0; i < n; i++)
    {
        cout << "POP" << endl;
    }
    for (int i = 1; i < n; i++)
    {
        cout << "PLACE " << i << endl;
    }
    cout << "PLACE " << n << endl;
    cout << "PHOTO" << endl;
    return;
}

int main()
{
    // init. INPUT
    int n;
    cin >> n;
    int *Arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        Arr[i] = n - i;
    }
    OmletDC(Arr, n);
    int count = 2 * n + ((n + 1) * n / 2 - 1) * 2;
    cout << count << endl;
    return 0;
}