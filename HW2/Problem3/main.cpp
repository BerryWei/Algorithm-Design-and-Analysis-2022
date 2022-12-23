// ta 課、與同學討論
#include <iostream>
#include <climits>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string INPUT;
    long long int K;
    cin >> INPUT;
    cin >> K;
    // covert into ASCII code
    vector<long long int> ASCII_Ori;
    for(long long int i = 0;i < INPUT.size(); i++)
    {
        ASCII_Ori.push_back(INPUT[i] - '0');
    }


    // 0 ~ z 有75個，全部填-1 
    vector<long long int> next(75, -1);
    vector<long long int> offset(75, 0);
    vector<long long int> output = ASCII_Ori;
    vector<long long int> used(ASCII_Ori.size(), 0);
    // 填在第 i 個位置，
    long long int temp;
    // next init
    for(long long int j = 0; j < ASCII_Ori.size(); j++)
    {
        if(next[ ASCII_Ori[j] ] == -1)
            next[ ASCII_Ori[j] ] = j;  
    }
/* PRINT
    for(int i = 0; i< next.size(); i++)
    {
        if(next[i] != -1)
        {
            cout << next[i] << " " << i  << " " << static_cast<char>(i +'0') << endl;
        }
        
    }
*/



    for(long long int i = 0; i < INPUT.size(); i++)
    {
        // 走過一次 0~z
        long long int j;
        for(j = 0; j < next.size(); j++)
        {
            // 看到可以拿的最小值是多少
            if(next[j] == -1)
                continue;
            // temp: 須要的步數
            temp = next[j] + offset[j] - i;
            if(temp <= K)
            {
                K = K - temp;
                break;
            }
        }
        // update output
        // output.push_back(ASCII_Ori[next[j]]);
        output[ i ] = ASCII_Ori[next[j]];
        // 用過的位置
        used[next[j]] = 1;

        // update offset
        for(long long int k = 0; k< next.size(); k++)
        {
            if(next[k] < next[j])
            {
                offset[k] ++;
            }
        }
        
        // update next
        long long int now_idx = next[j];
        next[j] = -1;
        for(long long int k = now_idx+1; k < ASCII_Ori.size(); k++)
        {
            // 下一個出現 j 的值的 index
            // update offset 後面用過了之後，不須要走那麼多步
            if( used[k] == 1 )
            {
                offset[j]--;
            }
            else if(ASCII_Ori[k] == j)
            {
                next[j] = k;
                break;
            }
        }
    }


    
    
    char* ans = new char [ASCII_Ori.size()];
    for(long long int i = 0; i< output.size(); i++)
    {
        ans[i] = static_cast<char>(output[i] + '0');
    }
    
    for(long long int i = 0; i < ASCII_Ori.size(); i++)
    {
        cout << ans[i] ;
    }
 
    return 0;
}