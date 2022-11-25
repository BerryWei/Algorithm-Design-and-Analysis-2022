// TA
#include <iostream>
#include <stack>
#include<list>
#include<vector>
#include<string>
#include <math.h>

#define int long long

using namespace std;


struct Spair
{
    int val;
    int rank;
    Spair(int v, int i){val=v; rank=i;}
};

bool valLarger(Spair p1, Spair p2)
{
    if(p1.val < p2.val)
        return true;
    return false;
}
bool rankLarger(Spair p1, Spair p2)
{
    if(p1.rank < p2.rank)
        return true;
    return false;
}

signed main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N, temp1, temp2, drop, sum;
    int soFarSum = 0;
    int n_PS = 0;
    int n_S = 0;;
    string stemp;
    cin >> N;
    vector<Spair> PS, S;


    for(int i = 0; i<N; i++)
    {
        cin >> stemp;
        if(stemp == "PUT")
        {
            cin >> temp1;
            soFarSum += temp1;
            n_PS++;n_S++;
            
            S.push_back(   Spair(temp1, i) );
            PS.push_back(  Spair(soFarSum, i) );
            cout << "PUT " <<  '\n';
        } else if(stemp == "TAKE")
        {
            cout << "TAKE" << '\n';
        } else if(stemp == "CC")
        {
            cin >> temp1 >> temp2;
            drop = static_cast<int>(floor(static_cast<double>(temp1)/ static_cast<double>(temp2) ) );
            
            // copy S
            vector<Spair> copyS(S);
            // sort copy S
            sort(copyS.begin(), copyS.end(), valLarger);
            // pop out
            for(int i =0; i< drop;i++)
            {
                n_PS--;n_S--;
                copyS.pop_back();
            }
                
            // Update S
            sort(copyS.begin(), copyS.end(), rankLarger);
            S.assign(copyS.begin(), copyS.end());
            //for(auto i: S)
            //    cout << i.val << " ";
            //cout << endl;

            // Update PS
            sum = 0;
            for(int i = 0; i< n_PS; i++)
            {
                sum += S[i].val;
                PS[i].val = sum;
            }

            

            /*
            for(auto i: S)
                cout << i.val << " ";
            for(auto i: PS)
                cout << i.val << " ";
            */
            


            cout << "CC  " << drop << '\n';
        } else
        {
            cin >> temp1;
            cout << "DD  " << PS[n_PS-1].val - PS[n_PS-1-temp1].val <<  '\n';
        }
    }
    
    





    return 0;
}