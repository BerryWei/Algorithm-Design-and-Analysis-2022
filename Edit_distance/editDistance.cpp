#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int sa(string & a, int & m, string & b, int & n,int **Matrix)
{
    // fill Matrix
    for(int i = 0; i <= m; i++)
    {
        for(int j = 0; j <= n; j++)
        {
            if( i == 0 )
            {
                Matrix[i][j] = j;
                continue;
            }
            if( j == 0 )
            {
                Matrix[i][j] = i;
                continue;
            }
            
            if( a[i-1] == b[j-1] )
            {
                Matrix[i][j] = min(Matrix[i-1][j] +1 , min(Matrix[i][j-1] + 1, Matrix[i-1][j-1]) );
                continue;
            }
            Matrix[i][j] = min(Matrix[i-1][j] +1 , min(Matrix[i][j-1] + 1, Matrix[i-1][j-1] + 1) );
            
        }
    }
    //
    return Matrix[m][n];

}






int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    string a, b;
    std::getline(cin, a);
    std::getline(cin, b);
    
    
    // calc string a, b length;
    int m = a.length();
    int n = b.length();

    // build a table M
    int **Matrix;
    Matrix =  new int * [m+1];
    for (size_t i = 0; i <= m; i++)
    {
        Matrix[i] = new int[n+1];
    }

    int nb= sa(a, m, b, n, Matrix);
    cout << nb << '\n';

/*
    for(int i = 0; i < m+1; i++)
        {
            for(int j = 0; j< n+1; j++)
            {
                cout << Matrix[i][j] << " ";
            }
            cout << endl;
        }
*/



    // free dynamically allocated memory
    for( int i = 0 ; i < m ; i++ )
    {
        delete[] Matrix[i]; // delete array within matrix
    }
    // delete actual matrix
    delete[] Matrix;

    


    return 0;
}