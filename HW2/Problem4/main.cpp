// ta 課、與同學討論
#include <iostream>
#include <climits>
#include <string.h>

using namespace std;

long long int Mod(long long int a, long long int b, long long int M)
{
    long long int output = a + b ;
    while( output >= M)
        output = output - M;

    return output;
}



long long int photos(long long int N, long long int K, long long int M)
{
    // N 差分數對
    N = N+1;

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
    long long int **UD = new long long int* [K+1];
    for(long long int i = 0; i < K+1 ; i++)
        UD[i] = new long long int [K+1];
    for(long long int i = 0; i<= K; i++)
        for(long long int j = 0; j<= K;j++)
            UD[i][j] = 0;
    
    //
    long long int **LR = new long long int* [K+1];
    for(long long int i = 0; i < K+1 ; i++)
        LR[i] = new long long int [K+1];
    for(long long int i = 0; i<= K; i++)
        for(long long int j = 0; j<= K;j++)
            LR[i][j] = 0;


    // N = 2;
   for(long long int i = 0; i <= K; i++)
    {
        for(long long int j = 0;j <= i;j++)
        {
            if( j == 0)
                Save[i][j] = i+1;
            else if(j ==0 && i != 0)
                Save[i][j] = 2;
            else
                Save[i][j] = 1;
        }
    }
 
    

    

   // Matrix[n][i][j] "用完" i 個 +1，"用完"j 個-1，有幾種圖形
    for(int n = 3; n <= N; n++)
    {
        for(int i = 0; i <= K; i++)
        {
            long long int temp = 0;
            for(int j = 0; j<= i; j++)
            {
               temp += Save[i][j];
               //temp = Mod(temp, Save[i][j], M);
               LR[i][j] = temp;
            }
        }

        for(int j = 0; j <= K; j++)
        {
            long long int temp = 0;
            for(int i = j; i<= K; i++)
            {
                temp += Save[i][j];
                //temp = Mod(temp, Save[i][j], M);
                UD[i][j] = temp;
            }
        }

        for(int i = 0; i <= K; i++)
        {
            for(int j = 0; j<= i; j++)
            {
                //Matrix[i][j] = LR[i][j] + UD[i][j] - Save[i][j];
                //Matrix[i][j] = Mod(Matrix[i][j], LR[i][j], M);
                //Matrix[i][j] = Mod(Matrix[i][j], UD[i][j], M);
                //Matrix[i][j] = Mod(Matrix[i][j], -1*Save[i][j], M);
                Matrix[i][j] = (LR[i][j] + UD[i][j] - Save[i][j]) % M;

            }
        }

        // Matrix -> Save
        for(int i=0; i<= K; i++)
        {
            for(int j =0; j<=K; j++)
                Save[i][j] = Matrix[i][j];
        }
        
    }
    

    
    

    long long int output = 0;
    for(int i = 0; i <= K; i++)
        output = Mod(output, Matrix[i][i], M);


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