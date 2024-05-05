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

     return 0;
}