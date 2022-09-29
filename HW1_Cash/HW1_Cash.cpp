#include <iostream>
#include <algorithm>

using namespace std;
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

void OptimalPick(int *residual, int&m, int *arrCost, int &n)
{
    // residual is original array [1,2,3,...,n]
    // build hashing table
    int *table = new int[m+1];
    for(int i = 0; i < m; i++)
    {
        table[i] = INT32_MAX;
    }
    ////////////////////
    // base cases
    ////////////////////
    // from 1~ minCost
    for(int i = 1; i < arrCost[0]; i++)
    {
        table[i] = i;
    }
    table[ arrCost[0] ] = 0;




    int num1, num2, sum12, temp1;
    bool isinArrCost;
    // from minCost ~ n
    for (int i = arrCost[0]+1; i <= m; i++)
    {
        // check if i is in arrCost 10
        isinArrCost = find(arrCost, arrCost + n, i) != arrCost + n;
        if(isinArrCost == true)
        {
            table[ i ] = 0;
            continue;
        }

        

        sum12 = INT32_MAX;
        for (int j = 1; j <= i/2; j++)
        {
            // 10 = 1+9 = 2+8 = ... = 5+5
            num1 = j;
            num2 = i - j;
            temp1 = table[num1] + table[num2];

            
            
            if(temp1 <= sum12)
            {
                sum12 = temp1;
            }
        }
        table[ i ] = sum12;

    }

    for(int i = 1; i<=m; i++)
    {
        residual[i] = table[i];
    }


}

int main()
{
    // init. variables
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
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
        residualOptimal[i] = INT32_MAX;
    }
    // Sorting Cost
    sort(arrCost, arrCost+n);

    residualZPicks(residualZ, m, arrCost, n);


    // Optimal Pick
    OptimalPick(residualOptimal, m, arrCost, n);
    /*
    for (size_t i = 1; i <= m; i++)
    {
        cout  << residualOptimal[i] << endl;
    }
    */
   
    // Conbine

    for (size_t i = 1; i <= m; i++)
    {
        cout  << residualZ[i-1] - residualOptimal[i] << endl;
    }




    return 0;
}