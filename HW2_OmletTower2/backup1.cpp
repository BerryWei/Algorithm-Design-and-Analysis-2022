// ta 課、與同學討論
#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

long long int Mod(long long int a, long long int b, long long int M)
{
    long long int output = a + b;
    while( output >= M)
        output = output - M;

    return output;
}



long long int photos(long long int N, long long int K, long long int M)
{
    // delare DP multiarray DP[n][k][m] index 1 ~ n的個前綴合等於k 且用了 m 個 +1；
    // N 差分數對
    N = N+1;
    K = K;
    
    long long int **Matrix = new long long int* [K+1];
    for(long long int i = 0; i <= K ; i++)
        Matrix[i] = new long long int [K+1];
    for(long long int i = 0; i<= K; i++)
        for(long long int j = 0; j<= K;j++)
            Matrix[i][j] = 0;

    //
    long long int **Save = new long long int* [K+1];
    for(long long int i = 0; i < K+1 ; i++)
        Save[i] = new long long int [K+1];
    for(long long int i = 0; i<= K; i++)
        for(long long int j = 0; j<= K;j++)
            Save[i][j] = 0;
    //

    // N = 2;
    for(long long int i = 0; i <= K; i++)
    {
        for(long long int j = 0;j <= i;j++)
        {
            if( j ==0)
                Save[i][j] = i+1;
            else if(j ==0 && i != 0)
                Save[i][j] = 2;
            else
                Save[i][j] = 1;
        }
    }


cout << "----------- 長度為2的數列 +1 有i 個，-1有j 個，共有 Save[i][j] 種排列 " << endl;  
for(long long int i = 0; i <= K; i++)
    {
        for(long long int j = 0;j <= i;j++)
        {
            cout << Save[i][j] << " " ;
        }
        cout << endl;
    }
cout << "-----------" << endl;


    // N = 3
    for(long long int n = 3; n <= N;n++)
    {
        // 垂直的加下來
        for(long long int j = 0; j <= K; j++)
        {
            long long int sum = 0;
            for(long long int i = j;  i<= K; i++)
            {
                //sum += Save[i][j];
                //sum = Mod(sum, Save[i][j], M);
                //sum = ( sum + Save[i][j]) % M;
                sum = Mod(sum, Save[i][j], M);
                //sum = Mod(sum, Save[i][j], M);
                Matrix[i][j] = sum;
            }
        }
        // Copy Matrix to Save
        for(long long int i = 0; i <= K; i++)
        {
            for(long long int j = 0; j<= i; j++)
            {
                Save[i][j] = Matrix[i][j];
            }
        }
        
        // 水平的加過去
        
        long long int sumij = 0;
        for(long long int i = 0; i <= K; i++)
        {
            long long int sumj = 0;
            for(long long int j = 0; j <= i; j++)
            {
                //sum = Mod(sum, Save[i][j], M);
                //sum = ( sum + Save[i][j]) % M;
                sumj = Mod(sumj, Save[i][j], M);
                
                Matrix[i][j] = sumj;
            }
        }
        
        

        // Copy Matrix to Save
        for(long long int i = 0; i <= K; i++)
        {
            for(long long int j = 0; j<= i; j++)
            {
                Save[i][j] = Matrix[i][j];
            }
        }

    // PRINT

for(long long int i = 0; i <= K; i++)
{
    for(long long int j = 0; j<= i; j++)
    {
        cout << Matrix[i][j] << " ";
    }
    cout << '\n' ;
}
cout << '\n' ;


    }
    

    long long int output = 0;
    for(long long int i = 0; i<= K; i++)
    {
        //output = ( output + Matrix[i][i]) % M;
        output = Mod(output, Matrix[i][i], M);
    }
    return Matrix[K][K];
    
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long int N, K, M;
    cin >> N >> K >> M;
    cout << photos(N, K, M) << '\n' ;
    return 0;
}