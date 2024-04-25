#include <iostream>
#include <set>
using namespace std;

void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

int findLargest(int arr[], int n)
{
    // brute force --  o(nlogn)
    // sort(arr, arr + n);
    // return arr[n - 1];

    // optimal solution -- o(n)
    int largest = arr[0];
    for (int i = 0; i < n; i++)

    {
        if (arr[i] > largest)
            largest = arr[i];
    }
    return largest;
}

int findSecondLargest(int arr[], int n)
{
    // brute force -- o(2n)
    // int largest = arr[0];
    // int secondLargest = -1;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > largest)
    //     {
    //         largest = arr[i];
    //     }
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > secondLargest && arr[i] != largest)
    //     {
    //         secondLargest = arr[i];
    //     }
    // }
    // return secondLargest;

    // optimal -- o(n)
    int largest = arr[0];
    int secondLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secondLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] < largest)
        {
            secondLargest = arr[i];
        }
    }
    return secondLargest;
}

bool isSorted(int arr[], int n)

// 0(n)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > arr[i + 1] && i <= n)
            return false;
    }

    return true;
}

int removeDuplicates(int arr[], int n)
{
    // brute force -- 0(nlogn)
    // set<int> smt;
    // for (int i = 0; i < n; i++)
    // {
    //     smt.insert(arr[i]);
    // }
    // int index = 0;
    // for (auto it : smt)
    // {
    //     arr[index] = it;
    //     index++;
    // }
    // return index;

    // optimal -- o(n)
    int i = 0;
    for (int j = i; j < n; j++)
    {
        if (arr[j] != arr[i])
        {
            arr[i + 1] = arr[j];
            i = i + 1;
        }
    }
    return i + 1;
}

void leftRotateByOne(int arr[], int n)
{
    int temp = arr[0];
    for (int i = 0; i < n; i++)
        arr[i] = arr[i + 1];
    arr[n - 1] = temp;
}

void leftRotateByD(int arr[], int n, int d)
{
    // brute force -- n(n-d) S.c=0(n)
    // vector<int> temp(d);
    // copying first d elemnts in temp arr
    // for (int i = 0; i < d; i++)
    // temp[i] = arr[i];
    // shifting rest of elements at very start of arr
    // for (int i = 0; i < n - d; i++)
    // arr[i] = arr[i + d];
    // copying first d elements from temp array to original arr
    // for (int i = 0; i < d; i++)
    // arr[(n - d) + i] = temp[i];

    // optimal -- n(n) S.c=0(1)
    reverse(arr, arr + d);
    reverse(arr + d, arr + n);
    reverse(arr, arr + n);
}

void moveZeroesEnd(int arr[], int n)
{

    // brute froce -- o(n) S.C = o(n)
    // vector<int> temp;
    // putting non zeroes numbers in temp array
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != 0)
    //     {
    //         temp.push_back(arr[i]);
    //     }
    // }
    // copying numbers from temp array to original array
    // for (int i = 0; i < temp.size(); i++)
    // {
    //     arr[i] = temp[i];
    // }
    // filling remaining elements as 0
    // for (int i = temp.size(); i < n; i++)
    // {
    //     arr[i] = 0;
    // }

    // optimal -- o(n)  S.C = o(1)
    int i = 0, j = n - 1;
    while (i < j)
    {
        if (arr[i] == 0)
        {
            swap(arr[i], arr[j]);
            j--;
        }
        else
        {
            i++;
        }
    }
}

int findTarget(int arr[], int n, int target)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == target)
            return i;
    }
    return -1;
}

vector<int> findUnion(int arr1[], int arr2[], int n1, int n2)
{
    // brute force -- o(n1logn + n2logn) + o(n1+n2)  S.C = o(n1+n2) [ for set ] + o(n1+n2) [ for vector ]
    // set<int> smt;
    // vector<int> ans;
    // storing el of 1st array into set
    // for (int i = 0; i < n1; i++)
    //     smt.insert(arr1[i]);
    // storing el of 2nd array into set
    // for (int i = 0; i < n2; i++)
    //     smt.insert(arr2[i]);
    // copying unique elements from set to ans vector
    // for (auto it : smt)
    // {
    //     ans.push_back(it);
    // }
    // return ans;

    // optimal -- o(n1 + n2)  S.C = o(n1 + n2) [ for returning ans vector and not to solving  problem]
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n1 && j < n2)
    {
        if (arr1[i] <= arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }

    while (i < n1)
    {
        if (ans.size() == 0 || ans.back() != arr1[i])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < n2)
    {
        if (ans.size() == 0 || ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }

    return ans;
}

vector<int> findIntersection(int a[], int b[], int n1, int n2)
{

    // brute force o(n1*n2)  S.C = o(n2)
    // vector<int> vis(n2, 0);
    // vector<int> ans;
    // for (int i = 0; i < n1; i++)
    // {
    //     for (int j = 0; j < n2; j++)
    //     {
    //         if (a[i] == b[j] && vis[i] == 0)
    //         {
    //             ans.push_back(a[i]);
    //             vis[j] = 1;
    //             break;
    //         }
    //         if (b[j] > a[i])
    //             break;
    //     }
    // }
    // return ans;

    // optimal -- o(n1 + n2)  S.C = o(n1 + n2) [ to store ans and return ]
    int i = 0;
    int j = 0;
    vector<int> ans;
    while (i < n1 && j < n2)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }

    return ans;
}

int findMissing(int arr[], int n)
{
    // brute force -- o(n) S.C = 0(n);
    // vector<int> temp(n + 1, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     temp[arr[i]] = 1;
    // }
    // for (int i = 1; temp.size(); i++)
    // {
    //     if (temp[i] == 0)
    //         return i;
    // }
    // return -1;

    // optimal 1  -- o(n) S.C = o(1)
    // int sum = 0;
    // for (int i = 0; i < n - 1; i++)
    // {
    //     sum += arr[i];
    // }
    // int nSum = (n * (n + 1)) / 2;
    // return nSum - sum;

    // optimal 2  -- o(n) S.C = o(1)
    int xor1 = 0;
    int xor2 = 0;
    for (int i = 0; i < n - 1; i++)
    {
        xor2 = xor2 ^ arr[i];
        xor1 = xor1 ^ (i + 1);
    }
    xor1 = xor1 ^ n;
    return xor1 ^ xor2;
}

int maxConsecutiveOnes(int arr[], int n)
{
    int count = 0;
    int maxi = -1;
    for (int i = 0; i < n; i++)
    {

        if (arr[i] == 1)
            count++;
        else
            count = 0;

        if (count > maxi)
            maxi = count;
    }

    return maxi;
}

int numberOnce(int arr[], int n)
{
    // brute force -- o(n) S.C = o(n)
    // vector<int> hsh(n + 1, 0);
    // int maxi = arr[0];
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] < maxi)
    //         maxi = arr[i];
    // }
    // for (int i = 0; i < n; i++)
    //     hsh[arr[i]]++;
    // for (int i = 0; i < hsh.size(); i++)
    // {
    //     if (hsh[i] == 1)
    //         return i;
    // }
    // return -1;

    // optimal -- o(n)  S.C o(1)
    int xorr = 0;
    for (int i = 0; i < n; i++)
    {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}

int findMaxSub(int arr[], int n, int k)
{
    int left = 0;
    int right = 0;
    int maxLength = 0;
    int sum = arr[0];
    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }
        if (sum == k)
        {
            maxLength = max(maxLength, right - left + 1);
        }
        right++;
        if (right < n)
            sum += arr[right];
    }

    return maxLength;
}

int main()
{
    //===========================================================================
    // find largest element in an array
    // int arr[] = {3, 2, 1, 5, 2};
    // int n = 5;
    // int ans = findLargest(arr, n);
    // cout << "largest el : " << ans << endl;

    //===========================================================================
    // find second largest element in an array
    // int arr[] = {1, 2, 4, 7, 7, 5,};
    // int n = 6;
    // int ans = findSecondLargest(arr, n);
    // cout << "second largest el : " << ans << endl;

    //===========================================================================
    // check if array is sorted or not
    // int arr[] = {1, 2, 2, 3, 3, 4};
    // int n = 6;
    // bool ans = isSorted(arr, n);
    // ans == true ? cout << "arr is sorted" : cout << "arr is not sorted" << endl;

    //===========================================================================
    // remove duplicates from sorted array
    // int arr[] = {1, 2, 2, 3, 3, 4};
    // int n = 6;
    // int endIndex = removeDuplicates(arr, n);
    // printArray(arr, endIndex);

    //===========================================================================
    // left rotate the array by one place
    // int arr[] = {1, 2, 3, 4, 5};
    // int n = 5;
    // leftRotateByOne(arr, n);
    // printArray(arr, n);

    //===========================================================================
    // left rotate the array by D places
    // int arr[] = {1, 2, 3, 4, 5, 6, 7};
    // int n = 7;
    // cout << "enter value of d :" << endl;
    // int d;
    // cin >> d;
    // d = d % n;
    // leftRotateByD(arr, n, d);
    // printArray(arr, n);

    //===========================================================================
    // move zeroes to the end of array
    // int arr[] = {1, 0, 2, 3, 2, 0, 0, 4, 5, 1};
    // int n = 10;
    // moveZeroesEnd(arr, n);
    // printArray(arr, n);

    //===========================================================================
    // return first occurence of give element in array
    // int arr[] = {6, 7, 8, 4, 1};
    // int n = 5;
    // int target = 4;
    // int ans = findTarget(arr, n, target);
    // cout << "first occurence of " << target << " is at : " << ans;

    //===========================================================================
    // union of two sorted arrays
    // int arr1[] = {1, 1, 2, 3, 4, 5};
    // int arr2[] = {2, 3, 4, 4, 5, 6};
    // int n1 = 6, n2 = 6;
    // vector<int> ans = findUnion(arr1, arr2, n1, n2);

    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";

    //===========================================================================
    // intersection of two sorted arrays
    // int a[] = {1, 2, 2, 3, 3, 4, 5, 6};
    // int b[] = {2, 3, 3, 5, 6, 6, 7};
    // int n1 = 8, n2 = 7;
    // vector<int> ans = findIntersection(a, b, n1, n2);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";

    //===========================================================================
    // find the missing number in an array
    // int arr[] = {1, 2, 4, 5};
    // int n = 5;
    // int ans = findMissing(arr, n);
    // cout << "missing number is  : " << ans << endl;

    //===========================================================================
    // find the maximum consecutive ones in an array
    // int arr[] = {1, 1, 0, 1, 1, 1};
    // int n = 6;
    // int ans = maxConsecutiveOnes(arr, n);
    // cout << "maximum consecutvie ones are    : " << ans << endl;

    //===========================================================================
    // find the number in an array that appears only once
    // int arr[] = {1, 1, 3, 3, 2, 4, 4};
    // int n = 7;
    // int ans = numberOnce(arr, n);
    // cout << "number appearing once is  : " << ans << endl;

    //===========================================================================
    // longest  subarray with sum = k
    // int arr[] = {1, 2, 3, 1, 1, 1, 1};
    // int n = 7;
    // int k = 3;
    // int ans = findMaxSub(arr, n, k);
    // cout << "max sub-array with sum = " << k << " is of length : " << ans << endl;

    return 0;
}