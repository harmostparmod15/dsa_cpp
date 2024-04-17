#include <iostream>
#include <limits.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int mini = i;
        for (int j = i; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

void bubbleSort(int arr[], int n)
{
    for (int i = n - 1; i > 0; i--)
    {
        int didSwap = 0;

        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }
        if (didSwap == 0)
        {
            break;
        }
    }
}

void insertionSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

int main()
{

    //==================================================================================
    // Selection Sort
    // int arr[] = {13, 46, 24, 52, 20, 9};
    // int n = 6;
    // selectionSort(arr, n);
    // printArr(arr, n);

    //==================================================================================
    // Bubble Sort
    // int arr[] = {13, 46, 24, 52, 20, 9};
    // int n = 6;
    // bubbleSort(arr, n);
    // printArr(arr, n);

    //==================================================================================
    // Insertion Sort
    int arr[] = {13, 46, 24, 52, 20, 9};
    int n = 6;
    insertionSort(arr, n);
    printArr(arr, n);

    return 0;
}