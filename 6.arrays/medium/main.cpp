#include <iostream>
#include <map>
#include <unordered_set>
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

vector<int> rearrangeArr(int arr[], int n)
{
    // brute -- o(n) -- S.C = o(n)
    // vector<int> pos;
    // vector<int> neg;
    // vector<int> ans;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] < 0)
    //         neg.push_back(arr[i]);
    //     else
    //         pos.push_back(arr[i]);
    // }
    // for (int i = 0; i < n / 2; i++)
    // {
    //     ans.push_back(pos[i]);
    //     ans.push_back(neg[i]);
    // }
    // return ans;

    // optimal -- o(n) -- S.C = o(n)
    int pos = 0;
    int neg = 1;
    int i = 0;
    vector<int> temp(n);
    while (i < n)
    {
        if (arr[i] < 0)
        {
            temp[neg] = arr[i];
            neg += 2;
            i++;
        }
        else
        {
            temp[pos] = arr[i];
            pos += 2;
            i++;
        }
    }

    return temp;
}

void nextPerm(int arr[], int n)
{
    // o(n)
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] < arr[i + 1])
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        reverse(arr, arr + n);
    }

    for (int i = n - 1; i > index; i--)
    {
        if (arr[i] > arr[index])
        {
            swap(arr[i], arr[index]);
            break;
        }
    }

    reverse(arr + index + 1, arr + n);
}

vector<int> findLeader(int arr[], int n)
{

    // brute -- o(n^2) -- S.C == o(n) [ for storing ans in array]
    // vector<int> temp;
    // bool leader = true;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] < arr[j])
    //         {
    //             leader = false;
    //             break;
    //         }
    //         else
    //             leader = true;
    //     }
    //     if (leader == true)
    //         temp.push_back(arr[i]);
    // }
    // temp.push_back(arr[n - 1]);
    // return temp;

    // optimal -- o(n) -- S.C == o(n) [ for storing ans in array]
    int maxi = INT_MIN;
    vector<int> temp;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
            temp.push_back(arr[i]);
        }
    }
    reverse(temp.begin(), temp.end());
    return temp;
}

int longesCons(int arr[], int n)
{
    // better -- o(nlogn)
    // int longest = 1;
    // int count = 0;
    // int lastSmaller = INT_MIN;
    // sort(arr, arr + n);
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] - 1 == lastSmaller)
    //     {
    //         count++;
    //         lastSmaller = arr[i];
    //     }
    //     else if (arr[i] != lastSmaller)
    //     {
    //         count = 1;
    //         lastSmaller = arr[i];
    //     }
    //     longest = max(longest, count);
    // }
    // return longest;

    // optimal
    int longest = 1;
    unordered_set<int> st;

    for (int i = 0; i < n; i++)
        st.insert(arr[i]);

    for (auto it : st)
    {

        if (st.find(it - 1) == st.end())
        {
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end())
            {
                x = x + 1;
                cnt++;
            }
            longest = max(longest, cnt);
        }
    }

    return longest;
}

void markRow(int i, int arr[][4], int n, int m)
{
    for (int j = 0; j < m; j++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

void markCol(int j, int arr[][4], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i][j] != 0)
            arr[i][j] = -1;
    }
}

void matrixZero(int arr[][4], int n, int m)
{
    // brtue -- o( (n*m) * (n+m) )
    // finding zero and marking correspond row & col to -1
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (arr[i][j] == 0)
    //         {
    //             markRow(i, arr, n, m);
    //             markCol(j, arr, n, m);
    //         }
    //     }
    // }
    // marking - 1 to 0
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (arr[i][j] == -1)
    //             arr[i][j] = 0;
    //     }
    // }

    // better --o(n*m) -- S.C = o(n) + o(m)
    vector<int> row(n);
    vector<int> col(m);
    //  if curr el is 0 then storing its row and col index in separate arrays
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    // makring row and col
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

void myReverse(int arr[])
{
    int l = 0;
    int r = 4 - 1;
    while (l < r)
    {
        swap(arr[l], arr[r]);
        l++;
        r--;
    }
}

void rotate(vector<vector<int>> matrix, int n, int m, int ans[][4])
{
    //     // brute -- o(n^2) -- S.C = o(n^2)
    //     // for (int i = 0; i < n; i++)
    //     // {
    //     //     for (int j = 0; j < m; j++)
    //     //     {
    //     //         ans[j][n - (i + 1)] = matrix[i][j];
    //     //     }
    //     // }

    // optimal -- o(n) -- S.C = o(1)
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
        {
            if (i != j)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for (int i = 0; i < n; i++)
        {

            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
}

vector<int> spiralPrint(int arr[][4], int n, int m)
{
    // o(n^2) - S.C == o(n^2)
    int top = 0;
    int left = 0;
    int right = m - 1;
    int bottom = n - 1;
    vector<int> ans;

    while (top <= bottom && left <= right)
    {

        for (int i = left; i <= right; i++)
        {
            ans.push_back(arr[top][i]);
        }
        top++;
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(arr[i][right]);
        }
        right--;
        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                ans.push_back(arr[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(arr[i][left]);
            }
            left++;
        }
    }

    return ans;
}

int kSumSubArray(int arr[], int n, int k)
{
    // brute -- o(n^3)
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         if (sum == k)
    //             count++;
    //     }
    // }
    // return count;

    // optimal -- o(nlog) -- S.C = o(n)
    map<int, int> mpp;
    mpp[0] = 1;
    int preSum = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        int remove = preSum - k;
        count += mpp[remove];
        mpp[preSum] += 1;
    }

    return count;
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

    // ===========================================================================
    // re arrange array elements by sign
    // int arr[] = {3, 1, -2, -5, 2, -4};
    // int n = 6;
    // vector<int> ans = rearrangeArr(arr, n);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";

    // ===========================================================================
    // find  next smallest permutation
    // int arr[] = {1, 3, 2};
    // int n = 3;
    // nextPerm(arr, n);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    // ===========================================================================
    // leaders in an array
    // int arr[] = {10, 22, 12, 3, 0, 6};
    // int n = 6;
    // vector<int> ans = findLeader(arr, n);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";

    // ===========================================================================
    // longest consecutive sequence
    // int arr[] = {102, 4, 100, 1, 101, 3, 2, 1};
    // int n = 8;
    // int ans = longesCons(arr, n);
    // cout << "ans is : " << ans << endl;

    // ===========================================================================
    // set matrix to zero
    // int arr[][4] = {{1, 1, 1, 1}, {1, 0, 1, 1}, {1, 1, 0, 1}, {1, 0, 0, 1}};
    // int n = 4;
    // int m = 4;
    // matrixZero(arr, n, m);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << arr[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // ===========================================================================
    // rotate matrix by 90
    // int matrix[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    // vector<vector<int>> matrix{
    //     {1, 2, 3, 4},
    //     {5, 6, 7, 8},
    //     {9, 10, 11, 12},
    //     {13, 14, 15, 16}};
    // int n = 4;
    // int m = 4;
    // int ans[][4] = {{0}, {0}, {0}, {0}};
    // rotate(matrix, n, m, ans);
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // ===========================================================================
    // print matrix in spiraly way
    // int matrix[][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 1, 3, 2}, {3, 4, 5, 6}};
    // vector<int> ans = spiralPrint(matrix, 4, 4);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";

    // ===========================================================================
    // find max sub-array whooes sum is equsl to k ;
    int arr[] = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int n = 10;
    int k = 3;

    int ans = kSumSubArray(arr, n, k);
    cout << "ans is : " << ans << endl;

    return 0;
}