#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

int bsRoot(int n)
{
    int l = 0;
    int h = n / 2;
    int ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if ((mid * mid) <= n)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            h = mid - 1;
    }

    return ans;
}

int nRoot(int num, int n)
{
    int l = 0;
    int h = num;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;

        if (pow(mid, n) == num)
            return mid;
        else if (pow(mid, n) < num)
            l = mid + 1;
        else
            h = mid - 1;
    }
    return -1;
}

int reqTime(int arr[], int n, int hr)
{
    int totalhr = 0;
    for (int i = 0; i < n; i++)
    {
        totalhr += ceil(arr[i] / (hr * 1.0));
    }
    return totalhr;
}

int kokoBanana(int arr[], int n, int h)
{
    int maxEl = *max_element(arr, arr + n);
    int low = 1;
    int high = maxEl;
    int ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (reqTime(arr, n, mid) <= h)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

int possible(int arr[], int n, int day, int m, int k)
{
    int count = 0;
    int bookeh = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
            count++;
        else
        {
            bookeh += count / k;
            count = 0;
        }
    }
    bookeh += count / k;
    if (bookeh == m)
        return true;
    else
        return false;
}

int mBoquets(int arr[], int n, int m, int k)
{
    int low = *min_element(arr + 0, arr + n);
    int high = *max_element(arr + 0, arr + n);
    int ans = -1;
    if (n <= m * k)
        return -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (possible(arr, n, mid, m, k) == true)
        {
            ans = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return ans;
}

bool divisor(int arr[], int mid, int n, int thresh)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        // taking ceil value
        if (arr[i] % mid != 0)
            sum += (arr[i] / mid) + 1;
        else
            sum += arr[i] / mid;
    }
    if (sum <= thresh)
        return true;
    else
        return false;
}

int smallestDivisor(int arr[], int n, int thresh)
{
    int l = 1;
    int h = *max_element(arr + 0, arr + n);
    int ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        bool flag = divisor(arr, mid, n, thresh);
        if (flag == true)
        {
            ans = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return ans;
}

int daysRequired(vector<int> arr, int capacity)
{
    int days = 1;
    int load = 0;
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (load + arr[i] > capacity)
        {
            days += 1;
            load = arr[i];
        }
        else
        {
            load += arr[i];
        }
    }
    return days;
}

int shipCapacity(vector<int> arr, int days)
{
    int n = arr.size();
    int l = *max_element(arr.begin(), arr.end());
    int h = accumulate(arr.begin(), arr.end(), 0);
    int ans = -1;
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        int daysReq = daysRequired(arr, mid);
        if (daysReq <= days)
        {
            ans = mid;
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return ans;
}

int main()
{

    // ============================================================================
    //  find the square root of given number using B.S
    // int n = 121;
    // int ans = bsRoot(n);
    // cout << "ans : " << ans << endl;

    // ============================================================================
    //  find the  nth root of number
    // int num = 32;
    // int n = 5;
    // int ans = nRoot(num, n);
    // cout << "ans : " << ans << endl;

    // ============================================================================
    //  koko eating bananas
    // int arr[] = {3, 6, 2, 8};
    // int n = 4;
    // int h = 7;
    // int ans = kokoBanana(arr, n, h);
    // cout << "ans : " << ans << endl;

    // ============================================================================
    //  minimum days to make M boquets
    // int arr[] = {7, 7, 7, 7, 13, 11, 12, 7};
    // int n = 8;
    // int m = 2;
    // int k = 3;
    // int ans = mBoquets(arr, n, m, k);
    // cout << "  ans : " << ans << endl;

    // ============================================================================
    //  find the smallest divisor given a threshold
    // int arr[] = {1, 2, 5, 9};
    // int n = 4;
    // int thresh = 7;
    // int ans = smallestDivisor(arr, n, thresh);
    // cout << "ans : " << ans << endl;

    // ============================================================================
    //  capacity to hsip packages within d dayss
    // int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // int n = 10;
    // int day = 5;
    // int ans = shipCapacity(arr, n, day);
    // cout << "ans : " << ans << endl;

    return 0;
}