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

int kMissing(int arr[], int n, int k)
{
    int l = 0;
    int h = n - 1;
    while (l <= h)
    {
        cout << " l : " << l << endl;
        int mid = l + (h - l) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
            l = mid + 1;
        else
            h = mid - 1;
    }
    cout << " l2 : " << l << endl;
    cout << k << endl;
    return l + k;
}

bool canPlace(int arr[], int n, int mid, int cows)
{
    int count = 1;
    int last = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] - last >= mid)
        {
            count++;
            last = arr[i];
        }
        if (count >= cows)
            return true;
    }
    return false;
}

int aggCows(int arr[], int n, int cows)
{
    sort(arr + 0, arr + n);
    int l = 0;
    int h = (arr[n - 1] - arr[0]);
    while (l <= h)
    {
        int mid = l + (h - l) / 2;
        if (canPlace(arr, n, mid, cows))
            l = mid + 1;
        else
            h = mid - 1;
    }
    return h;
}

int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size();
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}

int findPages(vector<int> &arr, int n, int m)
{
    if (m > n)
        return -1;

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int students = countStudents(arr, mid);
        if (students > m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

double median(vector<int> &a, vector<int> &b)
{
    int n1 = a.size(), n2 = b.size();
    if (n1 > n2)
        return median(b, a);

    int n = n1 + n2;
    int left = (n1 + n2 + 1) / 2;
    int low = 0, high = n1;
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}

int kTwoSorted(int arr[], int n, int brr[], int m, int k)
{
    int index = 0;
    int ans = -1;
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {

        if (index == k)
        {
            return ans;
        }

        if (arr[i] <= brr[j])
        {
            ans = arr[i];
            index = index + 1;
            i++;
        }
        else
        {
            ans = brr[j];
            index = index + 1;
            j++;
        }
    }

    // hndling the i j position case
    if (i == n)
        i += 1;
    else if (j == n)
        j += 1;

    while (i <= n)
    {
        if (index == k)
        {
            return ans;
        }
        ans = arr[i];
        index = index + 1;
        i++;
    }

    while (j <= m)
    {
        if (index == k)
        {
            return ans;
        }
        ans = brr[j];

        index = index + 1;
        j++;
    }
    return -1;
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

    // ============================================================================
    //  Kth missing positive number in an array
    // int arr[] = {2, 3, 4, 7, 11};
    // int n = 5;
    // int k = 5;
    // int ans = kMissing(arr, n, k);
    // cout << "ans : " << ans << endl;

    // ============================================================================
    //  Aggressive cows
    // int arr[] = {5, 4, 3, 2, 1, 1000000000};
    // int n = 6;
    // int cows = 2;
    // int ans = aggCows(arr, n, cows);
    // cout << "ans : " << ans << endl;

    // ============================================================================
    //  Book allocation
    // vector<int> arr = {25, 46, 28, 49, 24};
    // int n = 5;
    // int m = 4;
    // int ans = findPages(arr, n, m);
    // cout << ans;

    // ============================================================================
    //  median of 2 sorted arrays
    // vector<int> arr = {1, 2, 3, 4};
    // vector<int> brr = {3, 4, 5};
    // double ans = median(arr, brr);
    // cout << "ans : " << ans << endl;

    // ============================================================================
    //  k-th element of 2 sorted arrays
    // int arr[] = {2, 3, 6, 12, 15, 18};
    // int brr[] = {1, 4, 8, 10};
    // int n = 6;
    // int m = 4;
    // int k = 8;
    // int ans = kTwoSorted(arr, n, brr, m, k);
    // cout << "ans : " << ans << endl;

    return 0;
}