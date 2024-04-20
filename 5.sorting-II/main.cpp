#include <iostream>
#include <vector>
using namespace std;

void sortThem(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    // comparing smaller elements and putting it in temp array
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
            right++;
        }
    }
    // if some elements are left in left array
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    // if  some elements are left in right array
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    // copy elements from temp array to original array
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

void mergeSort(int arr[], int s, int e)
{
    if (s == e)
        return;

    int mid = (s + e) / 2;
    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);
    sortThem(arr, s, mid, e);
}

int findPivot(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;
    while (i < j)
    {
        while (arr[i] <= pivot && i <= high - 1)
            i++;
        while (arr[j] > pivot && j >= low + 1)
            j--;

        if (i < j)
            swap(arr[i], arr[j]);
    }
    swap(arr[low], arr[j]);
    return j;
}

void qs(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = findPivot(arr, low, high);
        qs(arr, low, pivotIndex - 1);
        qs(arr, pivotIndex + 1, high);
    }
}

int main()
{
    //=====================================================================================
    // merge sort
    // int arr[] = {3, 1, 2, 4, 1};
    // int n = 5;
    // mergeSort(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    //=====================================================================================
    // quick sort
    // int arr[] = {3, 1, 2, 4, 1};
    // int n = 5;
    // qs(arr, 0, n - 1);
    // for (int i = 0; i < n; i++)
    //     cout << arr[i] << " ";

    return 0;
}