// https://www.techiedelight.com/maximum-sum-subarray-using-divide-conquer/
// https://emn178.pixnet.net/blog/post/88907691-最大子序列%28maximum-subarray%29
// 周遠同
#include <iostream>
#include <algorithm>

using namespace std;

long long int sum(long long int *arr, long long int i, long long int j)
{
    long long int summ = 0;
    for (long long int idx = i; idx <= j; idx++)
    {
        summ += arr[idx];
    }
    return summ;
}

long long int maxLeftSum(long long int *arr, long long int i, long long int j)
{
    long long int sumMax = INT32_MIN;
    long long int sum = 0;
    for (long long int idx = j; idx >= i; idx--)
    {
        sum += arr[idx];
        if (sum > sumMax)
        {
            sumMax = sum;
        }
    }
    return sumMax;
}

long long int maxRightSum(long long int *arr, long long int i, long long int j)
{
    long long int sumMax = INT32_MIN;
    long long int sum = 0;
    for (long long int idx = i; idx <= j; idx++)
    {
        sum += arr[idx];
        if (sum > sumMax)
        {
            sumMax = sum;
        }
    }
    return sumMax;
}

long long int maxSubArray(long long int *arr, long long int i, long long int j)
{
    if (i >= j)
    {
        return arr[i];
    }

    // 找出 maxSubArray 是在左半邊(包括 mid)、右半邊（不包括 mid)還是中間
    long long int mid = (i + j) / 2;
    // 左半邊、右半邊取大
    long long int maxLR = max(maxSubArray(arr, i, mid), maxSubArray(arr, mid + 1, j));
    // 計算中間
    long long int crossMidsum = maxLeftSum(arr, i, mid) + maxRightSum(arr, mid + 1, j);
    // cout << crossMidsum << ", ";
    return max(maxLR, crossMidsum);
}

int main()
{
    int n;
    cin >> n;
    long long int *arr = new long long int[n];
    for (long long int i = 0; i < n; i++)
        cin >> arr[i];

    //  initialize
    long long int val = maxSubArray(arr, 0, n - 1);
    cout << val << endl;
    return 0;
}
