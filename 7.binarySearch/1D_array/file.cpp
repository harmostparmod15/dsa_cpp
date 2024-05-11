#include <iostream>
using namespace std;
int lowerBound(int arr[], int n, int target)
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

int upperBound(int arr[], int n, int target)
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

int main()
{

    int arr[] = {5, 7, 7, 8, 8, 10};
    int n = 6;
    int target = 6;
    int ans = upperBound(arr, n, target);
    int ans2 = lowerBound(arr, n, target);
    cout << "lower bound is : " << ans2 << endl;
    cout << "upper bound is : " << ans << endl;
    return 0;
}