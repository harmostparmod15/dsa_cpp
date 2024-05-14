#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int bs(int arr[], int n, int target)
{
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return mid;
        else if (target > arr[mid])
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int bsRecursive(int arr[], int s, int e, int target)
{
    int mid = s + (e - s) / 2;
    // base case 1
    if (s > e)
        return -1;

    // base case 2
    if (arr[mid] == target)
        return mid;

    else if (target > arr[mid])
    {
        int ans = bsRecursive(arr, mid + 1, e, target);
        return ans;
    }
    else
    {
        int ans = bsRecursive(arr, 0, mid - 1, target);
        return ans;
    }
}

int lowerBound(int arr[], int n, int target)
{
    int ans = n;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (target > arr[mid])
            s = mid + 1;
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int upperBound(int arr[], int n, int target)
{
    int ans = n;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

int searchInsert(int arr[], int n, int target)
{
    int s = 0;
    int e = n - 1;
    int ans = n;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int floor(int arr[], int n, int target)
{
    int ans = -1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] <= target)
        {
            ans = arr[mid];
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int lowerBound2(int arr[], int n, int target)
{
    int ans = -1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (target > arr[mid])
            s = mid + 1;
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int upperBound2(int arr[], int n, int target)
{
    int ans = -1;
    int s = 0;
    int e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > target)
        {
            e = mid - 1;
        }
        else
            s = mid + 1;
    }
    return ans;
}

vector<int> firstLastOcc(int arr[], int n, int target)
{
    vector<int> ans;
    int up = upperBound2(arr, n, target);
    int lo = lowerBound2(arr, n, target);
    ans.push_back(lo);
    ans.push_back(up);

    return ans;
}

int search(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
            return mid;

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= k && k <= arr[high])
            {

                low = mid + 1;
            }
            else
            {

                high = mid - 1;
            }
        }
    }
    return -1;
}

bool searchII(int arr[], int n, int k)
{
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] == k)
            return true;

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low = low + 1;
            high = high - 1;
            continue;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (arr[mid] <= k && k <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int findMin(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mini = INT_MAX;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < mini)
        {
            mini = arr[mid];
        }
        else if (arr[mid] < arr[e])
            e = mid - 1;

        else if (arr[s] <= arr[mid])
            s = mid + 1;
    }
    return mini;
}

int NumOfRotation(int arr[], int n)
{
    int s = 0;
    int e = n - 1;
    int mini = INT_MAX;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] < mini)
        {
            mini = arr[mid];
            ans = mid;
        }
        else if (arr[mid] < arr[e])
            e = mid - 1;

        else if (arr[s] <= arr[mid])
            s = mid + 1;
    }
    return ans;
}

int singleEl(int arr[], int n)
{
    // brute -- o(n)
    // int ans = -1;
    // if (n == 1)
    //     return arr[0];
    // for (int i = 0; i < n; i++)
    // {
    //     if (i == 0)
    //     {
    //         if (arr[i] != arr[i + 1])
    //             ans = arr[i];
    //     }
    //     else if (i == n - 1)
    //     {
    //         if (arr[i] != arr[i - 1])
    //             ans = arr[i];
    //     }
    //     else
    //     {
    //         if (arr[i] != arr[i - 1] && arr[i] != arr[i + 1])
    //         {
    //             ans = arr[i];
    //             break;
    //         }
    //     }
    // }
    // return ans;

    // optimal (logn)
    int s = 1;
    int e = n - 2;
    int ans = -1;
    if (n == 1)
        return arr[0];
    if (arr[0] != arr[1])
        return arr[0];
    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] != arr[mid - 1] && arr[mid] != arr[mid] + 1)
            return arr[mid];

        if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
            s = mid + 1;
        else
            e = mid - 1;
    }
    return -1;
}

int findPeak(int arr[], int n)
{
    int s = 1;
    int e = n - 2;
    if (n == 1)
        return arr[0];
    if (arr[0] > arr[1])
        return arr[0];
    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
            return arr[mid];
        else if (arr[mid] < arr[mid + 1])
            s = mid + 1;
        else if (arr[mid - 1] > arr[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    return -1;
}

int main()
{

    // ========================================================================================
    //  binary search on 1-D array
    // int arr[] = {3, 4, 6, 7, 9, 12, 16, 17};
    // int n = 8;
    // int target = 4;
    // int ans = bs(arr, n, target);
    // cout << "target found at index : " << ans << endl;

    // ========================================================================================
    //  binary search on 1-D array using recursion
    // int arr[] = {3, 4, 6, 7, 9, 12, 16, 17};
    // int n = 8;
    // int target = 122;
    // int ans = bsRecursive(arr, 0, n - 1, target);
    // cout << "target found at index : " << ans << endl;

    // ========================================================================================
    // find lower bound of an array
    // int arr[] = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    // int n = 10;
    // int target = 4;
    // int ans = lowerBound(arr, n, target);
    // cout << "lower bound is : " << ans << endl;

    // ========================================================================================
    // find upper bound of an array
    // int arr[] = {5, 7, 7, 8, 8, 10};
    // int n = 6;
    // int target = 6;
    // int ans = upperBound(arr, n, target);
    // cout << "upper bound is : " << ans << endl;

    // ========================================================================================
    // search insert position
    // int arr[] = {1, 3, 5, 6};
    // int n = 4;
    // int target = 5;
    // int ans = searchInsert(arr, n, target);
    // cout << "ans is : " << ans << endl;

    // ========================================================================================
    // find floor of target element in an array
    // int arr[] = {10, 25, 30, 40, 50};
    // int n = 5;
    // int target = 25;
    // int ans = floor(arr, n, target);
    // cout << ans << endl;

    // ========================================================================================
    // find first and last occurence of taret in an array
    // int arr[] = {5, 7, 7, 8, 8, 10};
    // int n = 6;
    // int target = 8;
    // vector<int> ans = firstLastOcc(arr, n, target);
    // cout << "first occurence is : " << ans[0] << endl;
    // cout << "last occurence is : " << ans[1] << endl;

    // ========================================================================================
    // search in a rotated sorted array
    // int arr[] = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    // int n = 9;
    // int target = 1;
    // int ans = search(arr, n, target);
    // cout << "ans : " << ans << endl;

    // ========================================================================================
    // search in a rotated sorted array -- version -II with duplicates element
    // int arr[] = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    // int target = 3;
    // int n = 10;
    // int ans = searchII(arr, n, target);
    // ans == true ? cout << "element exist " : cout << "element no exist";

    // ========================================================================================
    // find minimum in the rotated sorted array
    // int arr[] = {4, 5, 6, 7, 1, 1};
    // int n = 6;
    // int ans = findMin(arr, n);
    // cout << "minimum is : " << ans << endl;

    // ========================================================================================
    // find how many times array is rotated
    // int arr[] = {3, 4, 5, 1, 2};
    // int n = 5;
    // int ans = NumOfRotation(arr, n);
    // cout << "Number of rotations : " << ans << endl;

    // ========================================================================================
    // single elment in the sorted array
    // int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6, 7, 7};
    // int n = 13;
    // int ans = singleEl(arr, n);
    // cout << "ans is : " << ans << endl;

    // ========================================================================================
    // find peak element in an array
    // int arr[] = {1, 10, 13, 7, 6, 5, 4, 2, 1, 0};
    // int n = 10;
    // int ans = findPeak(arr, n);
    // cout << "peak element is : " << ans << endl;

    return 0;
}