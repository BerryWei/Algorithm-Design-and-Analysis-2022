#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

void Omlet(int *Arr, int n, queue<int> *q, stack<int> *stk)
{
    int count = 2 * n + ((n + 1) * n / 2 - 1) * 2;
    cout << count << endl;

    string str;
    // Take photo 1;
    for (int i = 0; i < n; i++)
    {
        stk->push(Arr[i]);
        cout << "PLACE " << Arr[i] << endl;
        count++;
    }
    cout << "PHOTO" << endl;
    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= j; i++)
        {
            int val = stk->top();
            stk->pop();
            q->push(val);
            cout << "POP" << endl;
        }
        while (q->empty() != true)
        {
            int val = q->front();
            q->pop();
            stk->push(val);
            cout << "PLACE " << val << endl;
        }
        cout << "PHOTO" << endl;
    }
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
    ///
    queue<int> q;
    stack<int> stk;
    Omlet(Arr, n, &q, &stk);

    return 0;
}