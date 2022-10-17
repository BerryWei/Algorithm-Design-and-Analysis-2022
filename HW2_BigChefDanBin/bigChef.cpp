// ta 課、與同學討論
#include <iostream>
#include <climits>
#include <algorithm>

using namespace std;

struct People
{
    long long int a;
    long long int b;
    People() = default;
    People(long long int A, long long int B){
        a = A;
        b = B;
    }
};

class Group
{
public:
    long long int m; // m people
    long long int max_eachGroup_CE = 0;
    long long int max_eachGroup_C = 0;
    People * peoples;
    Group() = default;
    Group(long long int M): m(M) {
        peoples = new People[m];
    }
    ~Group(){};
};

bool eating__(People p1, People p2)
{
    if(p1.b > p2.b)
        return true;
    return false;
}

bool waitTime__(Group g1, Group g2)
{
    if(g1.max_eachGroup_C * g2.m < g2.max_eachGroup_C * g1.m)
        return true;
    return false;
}

long long int cooking(long long int N, Group* groupArr)
{
    // 吃的最久的人先吃，先把每組依吃的時間排序
    for(long long int i = 0; i< N; i++)
    {
        sort(groupArr[i].peoples, groupArr[i].peoples + groupArr[i].m, eating__);
        // 計算最大吃+ 煮的時間
        groupArr[i].max_eachGroup_CE = LLONG_MIN;
        // 計算最大煮的時間
        groupArr[i].max_eachGroup_C = 0;
        for(long long int j = 0; j< groupArr[i].m; j++)
        {
            groupArr[i].max_eachGroup_C += groupArr[i].peoples[j].a;
            if(groupArr[i].max_eachGroup_C + groupArr[i].peoples[j].b > groupArr[i].max_eachGroup_CE)
                groupArr[i].max_eachGroup_CE = groupArr[i].max_eachGroup_C + groupArr[i].peoples[j].b;
        }
    }

    // Merge sort 排序讓別人等的時間少的排在前面
    sort(groupArr, groupArr + N, waitTime__);

    long long int current_cooking_time=0;
    for(long long int i = 0; i< N-1; i++)
    {
        current_cooking_time += groupArr[i].max_eachGroup_C;
        groupArr[i+1].max_eachGroup_CE += current_cooking_time;
        
    }

    long long int count  = 0;
    for(long long int i = 0; i< N; i++)
    {
        //cout << groupArr[i].max_eachGroup_CE << "  ";
        count += groupArr[i].max_eachGroup_CE * groupArr[i].m;
    }


    return count;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    long long int N, M, tempA, tempB;
    cin >> N;
    Group* groupArr = new Group[N];
    for(long long int i = 0; i< N; i++)
    {
        cin >> M;
        groupArr[i] = Group(M);
        
        for(long long int j = 0; j < M; j++)
        {
            cin >> tempA >> tempB;
            groupArr[i].peoples[j] = People(tempA, tempB);
        }
    }
    

    

    cout << cooking(N, groupArr) << '\n';
    
 
    return 0;
}