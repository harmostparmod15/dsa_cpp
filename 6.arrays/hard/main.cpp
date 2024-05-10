#include <iostream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int ncr(int n, int r)
{
    // o(r)
    // ncr = n!/r!*(n-r)! === (n to (n-r)!/r!
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

void printRow(int n)
{
    // o(n)
    cout << 1 << " ";
    long long ans = 1;
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / i;
        cout << ans << " ";
    }
    cout << endl;
}

void printPascal(int n)
{
    // o(N^2)
    for (int i = 1; i <= n; i++)
    {
        printRow(i);
    }
}

vector<int> findMajority(int arr[], int n)
{
    // brute -- o(n^2)
    // vector<int> tmp;
    // for (int i = 0; i < n; i++)
    // {
    //     if (tmp.size() == 0 || tmp[0] != arr[i])
    //     {
    //         int counter = 0;
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (arr[i] == arr[j])
    //                 counter++;
    //         }
    //         if (counter > n / 3)
    //             tmp.push_back(arr[i]);
    //         if (tmp.size() == 2)
    //             break;
    //     }
    // }
    // return tmp;

    // optimal -- o(n) -- S.C = o(n)
    vector<int> tmp;
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;

        if (mpp[arr[i]] > floor(n / 3))
            tmp.push_back(arr[i]);
    }
    return tmp;
}

vector<vector<int>> tripleSum(int arr[], int n, int p)
{
    // brute -- o(n^3) -- S.C = o(2 * no. of triplet)
    // set<vector<int>> st;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             if ((arr[i] + arr[j] + arr[k]) == p)
    //             {
    //                 vector<int> tmp = {arr[i], arr[j], arr[k]};
    //                 sort(tmp.begin(), tmp.end());
    //                 st.insert(tmp);
    //             }
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    // better -- 0(n^2) -- S.C = o(n)
    // set<vector<int>> st;
    // for (int i = 0; i < n; i++)
    // {
    //     set<int> hashSet;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int el = -(arr[i] + arr[j]);
    //         if (hashSet.find(el) != hashSet.end())
    //         {
    //             vector<int> temp = {arr[i], arr[j], el};
    //             sort(temp.begin(), temp.end());
    //             st.insert(temp);
    //         }
    //         hashSet.insert(arr[j]);
    //     }
    // }
    // vector<vector<int>> ans{st.begin(), st.end()};
    // return ans;

    // optimal  - o(n^2 + nlogn) -- S.C = o(no. of triplet) [ for returning ans ]
    vector<vector<int>> ans;
    sort(arr + 0, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j];
            if (sum < p)
                j++;
            else if (sum > p)
                k--;
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                i++;
                j--;
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

vector<vector<int>> fourSum(int arr[], int n, int p)
{
    // brute is using 4 loops - o(n^4)

    // better -- o(n^3 * logm) -- S.C = o(n)
    // vector<vector<int>> ans;
    // set<vector<int>> st;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         set<long long> hashSet;
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             long long sum = arr[i] + arr[j];
    //             sum += arr[k];
    //             long long el = p - -(sum);
    //             if (hashSet.find(el) != hashSet.end())
    //             {
    //                 vector<int> tmp = {arr[i], arr[j], arr[k], (int)el};
    //                 sort(tmp.begin(), tmp.end());
    //                 st.insert(tmp);
    //             }
    //             hashSet.insert(arr[k]);
    //         }
    //     }
    // }
    // return ans;

    // optimal -- o(n^2) -- S.C = o(m) [ only using for returining ans arr ]
    vector<vector<int>> ans;
    sort(arr + 0, arr + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && arr[i] == arr[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j != i + 1 && arr[j] == arr[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if (sum == p)
                {
                    vector<int> tmp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(tmp);
                    k++;
                    l--;
                    while (k < l && arr[k] == arr[k - 1])
                    {
                        k++;
                    }
                    while (k < l && arr[l] == arr[l + 1])
                        l--;
                }
                else if (sum < p)
                {
                    k++;
                }
                else
                    l--;
            }
        }
    }
    return ans;
}

int maxSubArr(int arr[], int n, int k)
{
    // brute [ using 3 nested loops ] -- o(n^3)

    // optimal  o(nlogn) -- S.C = o(n)
    map<int, int> mpp;
    int maxi = 0;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0)
            maxi = i + 1;
        else
        {
            if (mpp.find(sum) != mpp.end())
            {
                maxi = max(maxi, i - mpp[sum]);
            }
            else
            {
                mpp[sum] = i;
            }
        }
    }
    return maxi;
}

int countXor(int arr[], int n, int k)
{

    // brute -- o(n^2)
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     int xxor = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         xxor = xxor ^ arr[j];
    //         if (xxor == k)
    //             count++;
    //     }
    //     }
    // return count;

    // optimal -- o(n) -- S.C = o(n)
    int count = 0;
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++;
    for (int i = 0; i < n; i++)
    {
        xr = xr ^ arr[i];
        int x = xr ^ k;
        count += mpp[x];
        mpp[xr]++;
    }

    return count;
}

vector<vector<int>> mergeOlppingInterval(vector<vector<int>> arr)
{
    // o(nlogn) -- S.C = o(n)
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;

    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

void mergeArr(int arr[], int brr[], int n1, int n2)
{
    // brute -- o(n+m) -- S.C = o(n+m)
    // int i = 0;
    // int j = 0;
    // vector<int> tmp;
    // // merging both arrays
    // while (i < n1 && j < n2)
    // {
    //     if (arr[i] <= brr[j])
    //     {
    //         tmp.push_back(arr[i]);
    //         i++;
    //     }
    //     else
    //     {
    //         tmp.push_back(brr[j]);
    //         j++;
    //     }
    // }
    // if (i < n1)
    // {
    //     while (i < n1)
    //     {
    //         tmp.push_back(arr[i]);
    //         i++;
    //     }
    // }
    // if (j < n2)
    // {
    //     while (j < n2)
    //     {
    //         tmp.push_back(brr[j]);
    //         j++;
    //     }
    // }
    // inserting back in 1st array
    // for (int i = 0; i < n1; i++)
    // {
    //     arr[i] = tmp[i];
    // }
    // // inserting back in 2nd array
    // for (int j = 0; j < n2; j++)
    // {
    //     brr[j] = tmp[n1 + j];
    // }

    // optimal 1 -- o( nlogn + mlogm ) -- S.C = o(1)
    int i = n1 - 1;
    int j = 0;
    while (arr[i] >= brr[j])
    {
        swap(arr[i], brr[j]);
        i--;
        j++;
    }

    sort(arr + 0, arr + n1);
    sort(brr + 0, brr + n2);
}

vector<int> findRepeatAndMiss(int arr[], int n)
{
    // brute -- o(n^2) -- S.C = o(1)
    // vector<int> ans;
    // for (int i = 1; i <= n; i++)
    // {
    //     int counter = -1;
    //     int repeat = -1;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (i == arr[j])
    //             counter++;
    //     }
    //     if (counter == 1)
    //         ans.push_back(i);
    //     else if (counter == -1)
    //         ans.push_back(i);
    //     if (ans.size() == 2)
    //         break;
    // }
    // return ans;

    // better -- o(n) -- S.c = o(n)
    // vector<int> hsh(n + 1, 0);
    // vector<int> ans;
    // hashing
    // for (int i = 0; i < n; i++)
    //     hsh[arr[i]]++;
    // iterating over hash arr
    // for (int i = 1; i < hsh.size(); i++)
    // {
    //     if (hsh[i] == 2)
    //         ans.push_back(i);
    //     else if (hsh[i] == 0)
    //         ans.push_back(i);
    //     if (ans.size() == 2)
    //         break;
    // }
    // return ans;

    // optimal -- o(n) -- S.C = o(1)
    long long sn = (n * (n + 1)) / 2;
    long long s2n = (n * (n + 1) * (2 * n + 1)) / 6;
    long long s = 0, s2 = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        s2 += (long long)arr[i] * (long long)arr[i];
    }
    long long first = s - sn;
    long long second = s2 - s2n;
    second = second / first;
    long long x = (first + second) / 2;
    long long y = second - x;
    vector<int> ans;
    ans.push_back((int)x);
    ans.push_back((int)y);
    return ans;
}

int merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    int cnt = 0;
    if (low >= high)
        return cnt;
    int mid = (low + high) / 2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid + 1, high);
    cnt += merge(arr, low, mid, high);
    return cnt;
}

int countInversion(int arr[], int n)
{
    // brute -- o(n^2)
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] > arr[j])
    //             count++;
    //     }
    // }
    // return count;

    // optimal -- o(nlogn) -- S.C = o(n) using merge sort algo
    vector<int> v;
    for (int i = 0; i < n; i++)
        v.push_back(arr[i]);
    return mergeSort(v, 0, n - 1);
}

int reversePairs(int arr[], int n)
{
    // brute -- o(n^2)
    int count = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] > 2 * arr[i])
                count++;
        }
    }

    return count;
}

int maxProduct(int arr[], int n)
{
    // brute -- o(n^2)
    // int maxi = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     int pr = 1;
    //     for (int j = i; j < n; j++)
    //     {
    //         pr *= arr[j];
    //         maxi = max(maxi, pr);
    //     }
    //   }
    // return maxi;

    // optimal -- o(n)
    int pre = 1;
    int suf = 1;
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (pre == 0)
            pre = 1;
        if (suf == 0)
            suf = 1;
        pre *= arr[i];
        suf *= arr[n - i - 1];
        maxi = max(maxi, max(pre, suf));
    }

    return maxi;
}

int main()
{
    // ====================================================================================
    // find the elemet at rth row and cth col of pascal traingle
    // int r = 5;
    // int c = 3;
    // int ans = ncr(r - 1, c - 1);
    // cout << ans << endl;

    // ====================================================================================
    // print any row of pascal traingle
    // int n = 6;
    // printRow(n);

    // ====================================================================================
    // print n th row  row pascal traingle
    // int n = 6;
    // printPascal(n);

    // ====================================================================================
    // find majority element in an array occuring more than  n/3 times.
    // int arr[] = {1, 1, 3, 3, 3, 2, 2, 2};
    // int n = 8;
    // vector<int> ans = findMajority(arr, n);
    // cout << "ans is : " << ans[0] << " " << ans[1] << endl;

    // ====================================================================================
    // find triplet sum in array which is equal to p
    // int arr[] = {-1, 0, 1, 2, -1, -4};
    // int n = 6;
    // int p = 0;
    // vector<vector<int>> ans = tripleSum(arr, n, p);

    // ====================================================================================
    // find four sum in array which is equal to p
    // int arr[] = {1, 2, 1, 0, 1};
    // int n = 5;
    // int p = 5;
    // vector<vector<int>> ans = tripleSum(arr, n, p);

    // ====================================================================================
    // maximum sub-array
    // int arr[] = {1, -1, 3, 2, -2, -8, 1, 7, 10, 23};
    // int k = 0;
    // int n = 10;
    // int ans = maxSubArr(arr, n, k);
    // cout << "ans : " << ans << endl;

    // ====================================================================================
    // count sub-array with XOR as k
    // int arr[] = {4, 2, 2, 6, 4};
    // int n = 5;
    // int k = 6;
    // int ans = countXor(arr, n, k);
    // cout << "ans : " << ans << endl;

    // ====================================================================================
    // merge overlapping intervals
    // vector<vector<int>> arr = {{1, 3}, {2, 4}, {2, 6}, {8, 9}, {8, 10}, {9, 11}};
    // vector<vector<int>> ans =  mergeOlppingInterval(arr);
    // for(int i=0;i<ans.size();i++){
    //     for(int j=0;j<ans[i].size();j++){
    //         cout<<ans[i][j]<<" ";
    //     }
    // }

    // ====================================================================================
    // merge sorted arrays
    // int arr[] = {1, 3, 5, 7};
    // int brr[] = {0, 2, 6, 8, 9};
    // int n1 = 4;
    // int n2 = 5;
    // mergeArr(arr, brr, n1, n2);
    // for (int i = 0; i < n1; i++)
    //     cout << arr[i] << " ";
    // cout << endl;
    // for (int j = 0; j < n2; j++)
    //     cout << brr[j] << " ";

    // ====================================================================================
    // find missing and repeating element in an array
    // int arr[] = {4, 3, 6, 2, 1, 1};
    // int n = 6;
    // vector<int> ans = findRepeatAndMiss(arr, n);
    // cout << "repeating el : " << ans[0] << " missing el : " << ans[1] << endl;

    // ====================================================================================
    // count inversions in an array
    // int arr[] = {5, 3, 2, 4, 1};
    // int n = 5;
    // int ans = countInversion(arr, n);
    // cout << "ans : " << ans << endl;

    // ====================================================================================
    // reverse pairs in an aray
    // int arr[] = {1, 3, 2, 3, 1};
    // int n = 5;
    // int ans = reversePairs(arr, n);
    // cout << "ans : " << ans << endl;

    // ====================================================================================
    // maximum product  subarray
    // int arr[] = {2, 3, -2, 4};
    // int n = 4;
    // int ans = maxProduct(arr, n);
    // cout << "ans :" << ans << endl;

    return 0;
}