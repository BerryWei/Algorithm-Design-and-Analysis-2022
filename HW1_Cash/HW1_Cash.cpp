#include <iostream>
#include <algorithm>

void residualZPicks(int* residual,int &m, const int* arrCost, int &n)
{
    int res;
    for(int i = 0; i<m; i++)
    {
        for(int j = n-1; j>=0 ;j--)
        {
            res = residual[i]; 
            while ( (res - arrCost[j]) >= 0)
            {
                residual[i] -=  arrCost[j];
                res -= arrCost[j];
            }
        }
    }
    return;
}

using namespace std;
int main()
{
    // init. variables
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n  >> m;
    int *arrCost = new int[n];
    int *residualZ = new int[m];
    int *residualOptimal = new int[m];

    for (size_t i = 0; i < n; i++)
    {
        cin >> arrCost[i] ;
    }
    for (size_t i = 0; i < m; i++)
    {
        residualZ[i] = i+1;
    }
    for (size_t i = 0; i < m; i++)
    {
        residualOptimal[i] = i+1;
    }
    // Sorting Cost
    sort(arrCost, arrCost+n);

    // residual Z picks
    residualZPicks(residualZ, m, arrCost, n);
    for (size_t i = 0; i < m; i++)
    {
        cout  << residualZ[i] << endl;
    }
    

    return 0;
}