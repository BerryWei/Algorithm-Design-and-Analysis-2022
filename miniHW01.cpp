#include <iostream>

using namespace std;

int sum(int *arr, int i, int j)
{
    int summ = 0;
    for (int idx = i; idx <= j; idx++)
    {
        summ += arr[idx];
    }
    return summ;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    //  initialize
    int i = 0;
    int j = n - 1;
    int Sum = sum(arr, i, j);
    int currentSum = Sum;
    //
    int ii = i;
    int jj = j;

    while (ii <= jj)
    {
        ii++;

        currentSum = sum(arr, ii, j);

        if (currentSum > Sum && ii <= j)
        {
            Sum = currentSum;
            i = ii;
        }
        //
        jj--;

        currentSum = sum(arr, i, jj);
        if (currentSum > Sum && i <= jj)
        {
            Sum = currentSum;
            j = jj;
        }
        // cout << "currentSum(" << ii << " " << jj << "):" << currentSum << endl;
    }
    // cout << "i: " << i << endl;
    // cout << "j: " << j << endl;

    cout << sum(arr, i, j) << endl;
    return 0;
}