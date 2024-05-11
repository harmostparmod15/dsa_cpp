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

    return 0;
}