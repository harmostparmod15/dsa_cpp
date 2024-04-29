#include <iostream>
#include <map>
#include <vector>
#include <limits.h>
using namespace std;

vector<int> twoSum(vector<int> arr, int target)
{

    // brute -- o(n^2)
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     for (int j = 0; j < arr.size(); j++)
    //     {
    //         if (arr[i] + arr[j] == target)
    //             return true;
    //     }
    // }
    // return false;

    // better -- o(nlogn)
    // map<int, int> mpp;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int el = target - arr[i];
    //     if (mpp.find(el) != mpp.end())
    //         return {mpp[el], i};
    //     mpp[arr[i]] = i;
    // }
    // return {-1, -1};

    // optimal without using map -- o(nlogn)
    int n = arr.size();
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size() - 1;

    while (i < j)
    {
        if (arr[i] + arr[j] == target)
            return {i, j};
        else if (arr[i] + arr[j] < target)
            i++;
        else
            j--;
    }

    return {-1, -1};
}

void sortZeroeOneTwos(int arr[], int n)
{
    // better - o(n) -- S.C = o(1)
    // int countZero = 0;
    // int countOne = 0;
    // int countTwo = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == 0)
    //         countZero++;
    //     else if (arr[i] == 1)
    //         countOne++;
    //     else
    //         countTwo++;
    // }
    // vector<int> v;
    // for (int i = 0; i < countZero; i++)
    //     arr[i] = 0;
    // for (int i = 0; i < countOne; i++)
    //     arr[countZero + i] = 1;
    // for (int i = 0; i < countTwo; i++)
    //     arr[countOne + countZero + i] = 2;

    // optimal - o(n) -- S.C = o(1) [ dutch national flag algo ]
    int i = 0;
    int left = 0;
    int right = n - 1;
    while (i <= right)
    {
        if (arr[i] == 0)
        {
            swap(arr[left], arr[i]);
            left++;
            i++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[right], arr[i]);
            right--;
        }
        else
            i++;
    }
}

int moreOccur(int arr[], int n)
{
    // better -- o(nlogn) -- S.C = o(n)
    // map<int, int> mpp;
    // for (int i = 0; i < n; i++)
    // {
    //     mpp[arr[i]]++;
    // }
    // for (auto it : mpp)
    // {
    //     if (it.second > n / 2)
    //         return it.first;
    // }
    // return -1;

    // optimal -- o(n) -- S.C = o(1)  [ moore's voting algorithm]
    int el;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            el = arr[i];
            count = 1;
        }
        if (arr[i] == el)
            count++;
        else
            count--;
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == el)
            cnt1++;
    }

    if (cnt1 > n / 2)
        return el;

    return -1;
}

int maxSubArr(int arr[], int n)
{

    // optimal -- o(n) -- S.C = o(1)
    int sum = 0;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        maxi = max(sum, maxi);
        if (sum < 0)
            sum = 0;
    }
    return maxi;
}

int buySellStock(int arr[], int n)
{
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] > arr[i])
            {
                maxi = max(arr[j] - arr[i], maxi);
            }
        }
    }
    return maxi;
}

int main()
{

    // ===========================================================================
    // two sum in array
    // vector<int> arr{4, 1, 2, 3, 1};
    // int target = 5;
    // vector<int> ans = twoSum(arr, target);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";

    // ===========================================================================
    // sort 0s , 1s and 2s
    // int arr[] = {0, 1, 2, 0, 1, 2, 1, 2, 0, 0, 0, 1};
    // int n = 12;
    // sortZeroeOneTwos(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    // ===========================================================================
    // find element occuring more than n/2 times
    // int arr[] = {2, 2, 3, 3, 1, 2, 2};
    // int n = 7;
    // int ans = moreOccur(arr, n);
    // cout << "ans is : " << ans << endl;

    // ===========================================================================
    // maximum sub array sum
    // int arr[] = {-2, -3, 4, -1 - 2, 1, 5, -3};
    // int n = 8;
    // int ans = maxSubArr(arr, n);
    // cout << "ans is : " << ans << endl;

    // ===========================================================================
    // buy and sell stocks
    // int arr[] = {7, 1, 5, 3, 6, 4};
    // int n = 6;
    // int ans = buySellStock(arr, n);
    // cout << "ans is : " << ans << endl;

    return 0;
}