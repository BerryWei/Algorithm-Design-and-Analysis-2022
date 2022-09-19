#include <iostream>
#include <stack>
#include <queue>
#include <string>

using namespace std;

void Omlet(int *Arr, int n, queue<int> *q, stack<int> *stk)
{
    int count = 0;
    string str;
    // Take photo 1;
    for (int i = 0; i < n; i++)
    {
        stk->push(Arr[i]);
        // cout << "PLACE " << Arr[i] << endl;
        str += "PLACE ";
        str += to_string(Arr[i]);
        str += "\n";
        count++;
    }
    // cout << "PHOTO" << endl;
    str += "PHOTO";
    str += "\n";
    count++;
    for (int j = 2; j <= n; j++)
    {
        for (int i = 1; i <= j; i++)
        {
            int val = stk->top();
            stk->pop();
            q->push(val);
            // cout << "POP" << endl;
            str += "POP";
            str += "\n";
            count++;
        }
        while (q->empty() != true)
        {
            int val = q->front();
            q->pop();
            stk->push(val);
            // cout << "PLACE " << val << endl;
            str += "PLACE ";
            str += to_string(val);
            str += "\n";
            count++;
        }
        // cout << "PHOTO" << endl;
        str += "PHOTO";
        str += "\n";
        count++;
    }
    cout << count << endl;
    cout << str;
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