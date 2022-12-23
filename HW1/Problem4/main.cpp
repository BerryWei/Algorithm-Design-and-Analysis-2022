#include<iostream>
#include<algorithm>
#include<cstring>
#include<set>

using namespace std;

set<int> needInitL;
set<int> needInitR;

inline long long int calcCount(int & min1Val, int *table, int &val)
{
    
    long long int count = 0;
    if(val-min1Val > 0)
        count += table[val-min1Val];
    if(val+min1Val <= 100000)
        count += table[val+min1Val];
    return count;
}



long long int calcCross(int *tableL ,int *tableR, int *array, int &n, int lower, int mid, int high)
{
    /*
    for(int i=0; i< 100001; i++)
    {
        tableL[i] = 0;
        tableR[i] = 0;
    }
    */
    for (std::set<int>::iterator it = needInitL.begin(); it != needInitL.end(); it++)
        tableL[ *it ] = 0;
    for (std::set<int>::iterator it = needInitR.begin(); it != needInitR.end(); it++)
        tableR[ *it ] = 0;
    needInitL.clear();
    needInitR.clear();
    

   
    int idxL = mid;
    int idxR = mid+1;
    long long int count = 0;
    int min1Val = min(array[idxL], array[idxR]);;
    int min2Val = INT32_MAX;
    int temp;
    bool nextLeft = true;
    // find second min and ignore first min
    if (array[idxL] >= array[idxR]){
        min2Val = array[idxL];
        nextLeft = true;
    }else{
        min2Val = array[idxR];
        nextLeft = false;
    }
    
    while(idxL >=lower && idxR<=high)
    {
        if(nextLeft == true)
        {
            // 跟最小值比看看是否轉向，並且更新最小值
            temp = min(array[idxL], min1Val);
            if(temp < min1Val){
                min1Val = temp;
                nextLeft = false;
                continue;
            }
            // 更新第2小值
            if(array[idxL] < min2Val)
            {
                min2Val=array[idxL];
            }

            // update tableL 
            tableL[ array[idxL] ] += 1;
            needInitL.insert(array[idxL]);

            count += calcCount(min2Val, tableR, array[idxL]);
            //cout << "min1Val: " << min1Val << " " << array[idxL] << endl;
            idxL--;         
        }else
        {
            temp = min(array[idxR], min1Val);
            if(temp < min1Val){
                min1Val = temp;
                nextLeft = true;
                continue;
            }
            // 更新第2小值
            if(min2Val > array[idxR])
            {
                min2Val=array[idxR];
            }
            // update tableR
            tableR[ array[idxR] ] += 1;
            needInitR.insert(array[idxR]);
            count += calcCount(min2Val, tableL, array[idxR]);
            // cout  << array[idxR] << " " <<  min2Val << endl;
            idxR++;
            
        }
    }

    if(idxR == (high+1) )
    {
        // 右邊走到底--> always 往左走

        // 更新最小值
        if(array[idxL]< min1Val )
        {
            min1Val=array[idxL];
        }
        
        // 先走第一次        
        count += calcCount(min1Val, tableR, array[idxL]);
        idxL--;
        //cout << min1Val << endl;
        while(idxL >=lower)
        {
            
            // 更新最小值
            if(array[idxL]< min1Val )
            {
                min1Val=array[idxL];
            }
            
            count += calcCount(min1Val, tableR, array[idxL]);

            //cout << min2Val<< "  "   << array[idxL]<<"  " << calcCount(min2Val, tableR, array[idxL])<< endl;
            idxL--;
        }
        return count;
    }
    //cout << "count  " << count << endl;
    if(idxL == (lower -1) )
    {
        //  左邊走到底 -->更新左邊最小值
        
        // always 往右走
        // 先走第一步
        // 更新第2小值（最小值)
        
        if(array[idxR]<min1Val)
        {
            min1Val=array[idxR];
        }
        count += calcCount(min1Val, tableL, array[idxR]);
        idxR++;
        
        while(idxR <= high)
        {            
            if(array[idxR]<min1Val)
            {
                min1Val=array[idxR];
            }
            count += calcCount(min1Val, tableL, array[idxR]);
            idxR++;
        }
        return count;
    }



    return count;
}
long long int calcPair(int *tableL, int *tableR, int *array, int& n, int lower, int high)
{
    // divide;
    if(lower >= high)
        return 0;
    long long int count = 0;
    
    int mid = (lower+high)/2;

    count += calcPair(tableL, tableR, array, n, lower, mid);
    count += calcPair(tableL, tableR, array, n, mid+1, high);
    count += calcCross(tableL, tableR, array, n, lower, mid, high);

    return count;



}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    cin >> n;
    int *array = new int[n];
    for(int i=0;i<n;i++)
        cin >> array[i];

    int tableL[100001];
    int tableR[100001];
    //init table
    memset(tableL, 0, sizeof(int)*100001);
    memset(tableR, 0, sizeof(int)*100001);
    //int nbPairs = calcPair(array, n, 0, n-1);
    // int calcCross(int *array, int &n, int lower, int mid, int high);
    // int calcPair(int *array, int n, int lower, int high)
    long long int nbPairs = calcPair(tableL, tableR, array, n, 0, n-1);

    //int nbPairs = calcCross(array, n, 0, n/2, n-1);
    cout << nbPairs << endl;
    return 0;
}