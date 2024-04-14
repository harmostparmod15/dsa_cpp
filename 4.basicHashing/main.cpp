#include <iostream>
#include <map>
using namespace std;

void hashing(int arr[], int arrN, int hash[], int hashN)
{
    for (int i = 0; i < arrN; i++)
    {
        hash[arr[i]]++;
    }
}

void hashChar(string s, int hash[])
{
    for (int i = 0; i < s.size(); i++)
    {
        hash[s[i]]++;
    }
}

void hashNumberMap(int arr[], int n, map<int, int> &mpp)
{
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }
}

vector<int> getFrequencies(vector<int> &v)
{
    // Write Your Code Here
    map<int, int> mpp;
    for (int i = 0; i < v.size(); i++)
    {
        mpp[v[i]]++;
    }
    int max = INT_MIN;
    int largestEl = 0;
    int mini = INT_MAX;
    int smallestEl = 0;
    for (auto it : mpp)
    {
        if (it.second > max)
        {
            max = it.second;
            largestEl = it.first;
        }
        if (it.second < mini)
        {
            mini = it.second;
            smallestEl = it.first;
        }
    }

    vector<int> vr;
    vr.push_back(largestEl);
    vr.push_back(smallestEl);
    return vr;
}

int main()
{
    //=====================================================================
    // number based hashing  [array]
    // int arr[5] = {1, 2, 1, 3, 2};
    // int hash[13] = {0};
    // hashing(arr, 5, hash, 13);
    // for(int i =0;i<13 ;i++){
    //     cout<<"how many times "<<i<<" appers ? : "<<hash[i];
    // }

    //=====================================================================
    // charactr based hashing [array]
    // string s;
    // cout << "enter string" << endl;
    // cin >> s;
    // pre compute
    // int hash[256] = {0};
    // hashChar(s, hash);
    // output
    // cout << "enter no. of queries " << endl;
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     char ch;
    //     cout << "enter char : " << endl;
    //     cin >> ch;
    //     cout << hash[ch] << endl;
    // }

    //=====================================================================
    //  number based hashing [map]
    // int n;
    // cout << "enter size of array" << endl;
    // cin >> n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    // {
    //     cout << "enter value at " << i << " index " << endl;
    //     cin >> arr[i];
    // }
    // pre compute
    // map<int, int> mpp;
    // hashNumberMap(arr, n, mpp);
    // output
    // int q;
    // cout << "enter no. of querries" << endl;
    // cin >> q;
    // while (q--)
    // {
    //     int n;
    //     cout << "enter number" << endl;
    //     cin >> n;
    //     cout << mpp[n] << endl;
    // }

    //=====================================================================
    // find the highest and lowest frequency of elements in an arrqy
    // vector<int> v = {1, 2, 3, 1, 1, 4};
    // vector<int> ans = getFrequencies(v);
    // cout << ans[0] << "largest freq." << endl;
    // cout << ans[1] << "smallest freq." << endl;

    return 0;
}