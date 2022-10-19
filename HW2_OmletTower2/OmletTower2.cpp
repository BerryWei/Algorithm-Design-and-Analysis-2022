// ta 課、與同學討論
#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

long long int photos(long long int N, long long int K, long long int M)
{
    // delare DP multiarray DP[n][k][m] index 1 ~ n的個前綴合等於k 且用了 m 個 +1；
    // N 差分數對
    N = N+1;
    K = K;
    
    long long int **Matrix = new long long int* [K+1];
    for(long long int i = 0; i < K+1 ; i++)
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
            if(i == j)
                Save[i][j] = 1;
            else
                Save[i][j] = 2;
        }
    }

    // N = 3
    for(long long int n = 3; n<= N;n++)
    {
    long long int sum = 0;
    for(long long int i = 0; i <= K; i++)
    {
        for(long long int j = 0; j<= i; j++)
        {
            sum += Save[i][j];
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

    // PRINT
/*
for(int i = 0; i <= K; i++)
{
    for(int j = 0; j<= i; j++)
    {
        cout << Matrix[i][j] << " ";
    }
    cout << endl;
}
*/
    }
    

    long long int output = Matrix[K][K];
    output = output % M;
    
    return output;
    
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