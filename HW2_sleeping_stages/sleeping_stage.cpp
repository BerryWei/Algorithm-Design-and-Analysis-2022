#include <iostream>

using namespace std;

int count_stage(int N, int K, int *a)
{
    // init L
    int **L = new int* [K];
    for(int i = 0; i< K; i++)
        L[i] = new int [N];
        
    for(int i = 0; i< K; i++){
        for(int j = 0; j<N; j++)
            L[i][j] = 0;
    }
    // init R
    int **R = new int* [N];
    for(int i = 0; i< N; i++)
        R[i] = new int [N];
    for(int i = 0; i< N; i++){
        for(int j = 0; j<N; j++)
            R[i][j] = 0;
    }
    // fill R
    for(int i = 0; i< N; i++)
    {
        int max_so_far = INT32_MIN, max_ending_here = 0;
        for(int j = (N-i-1); j>= 0; j--)
        {
            max_ending_here = max_ending_here + a[j];
            if (max_so_far < max_ending_here)
                max_so_far = max_ending_here;
    
            if (max_ending_here < 0)
                max_ending_here = 0;
            R[i][j] = max_so_far * (   (N-i)-j  );
        }
    }
    // fill L :: k = 1
    int max_so_far = INT32_MIN, max_ending_here = 0;
    for(int j = 0; j < N; j++)
    {
        max_ending_here = max_ending_here + a[j];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0)
            max_ending_here = 0;
        L[0][j] = max_so_far * (j+1);
    }

    // fill L :: k>1
    int temp_min, temp;
    for(int i = 1; i< K; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(j < i)
                continue;

            temp_min = INT32_MAX;
            for(int k = 0; k< j; k++)
            {
                temp = L[i-1][k] + R[N - j - 1][k+1];
                if(temp < temp_min)
                    temp_min = temp;
            }
            L[i][j] = temp_min;
        }
    }    

// PRINT
/*
cout << endl;
for(int i = 0; i< K; i++)
{
    for(int j = 0; j < N; j++)
        cout << L[i][j] << " ";
    cout << endl;
}
*/
    
    return L[K-1][N-1];

}



int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    int K;
    cin >> N >> K;
    int *a = new int [N];
    for (int i = 0; i< N; i++)
        cin >> a[i];
    
    cout << count_stage(N, K, a) << '\n';
    return 0;
}