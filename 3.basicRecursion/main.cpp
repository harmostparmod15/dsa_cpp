#include <iostream>
#include <vector>
using namespace std;

int counter = 0;

void print()
{
    if (counter == 3)
        return;

    cout << counter << " ";
    counter++;
    print();
}

void printName(int i, int n)
{
    if (i > n)
        return;
    cout << "John Doe" << endl;

    printName(i + 1, n);
}

void print1ToN(int i, int n)
{
    if (i > n)
        return;
    cout << i << endl;
    print1ToN(i + 1, n);
}

void printNTo1(int i, int n)
{
    if (i == 0)
        return;

    cout << i << endl;
    printNTo1(i - 1, n);
}

void print1ToNBacktracking(int i, int n)
{
    if (i < 1)
        return;

    print1ToNBacktracking(i - 1, n);
    cout << i << endl;
}

void printNTo1Backtracking(int i, int n)
{
    if (i > n)
        return;
    printNTo1Backtracking(i + 1, n);
    cout << i << endl;
}

int sum(int n)
{
    if (n == 1)
        return 1;
    return n + sum(n - 1);
}

int factorial(int n)
{
    if (n == 1)
        return 1;
    return n * factorial(n - 1);
}

void reverseArray(int arr[], int size, int l, int r)
{
    if (l >= r)
        return;
    swap(arr[l], arr[r]);
    reverseArray(arr, size, l + 1, r - 1);
}

void reverseArrayVersion2(int i, int n, int arr[])
{
    if (i >= n / 2)
        return;

    swap(arr[i], arr[n - i - 1]);
    reverseArrayVersion2(i + 1, n, arr);
}

bool isPalindrome(string str, int l)
{
    if (l >= str.size() / 2)
        return true;
    if (str[l] == str[str.size() - l - 1])
    {
        return isPalindrome(str, l + 1);
    }
    else
    {
        return false;
    }
}

int fibonacci(int n)
{
    if (n <= 1)
        return n;

    int num1 = fibonacci(n - 1);
    int num2 = fibonacci(n - 2);
    return num1 + num2;
}

int main()
{

    // ===============================================================
    // basic recusrion to print numbers upto 3
    // print();

    // ===============================================================
    //  print name N time
    // cout << "enter the value of n :" << endl;
    // int n;
    // cin >> n;
    // printName(1, n);

    // ===============================================================
    // print from 1 to N
    // cout << "enter the value of n :" << endl;
    // int n;
    // cin >> n;
    // print1ToN(1, n);

    // ===============================================================
    // print from N to 1
    // cout << "enter the value of n :" << endl;
    // int n;
    // cin >> n;
    // printNTo1(n, n);

    // ===============================================================
    // print from   1 to N  using backtracking
    // cout << "enter the value of n :" << endl;
    // int n;
    // cin >> n;
    // print1ToNBacktracking(n, n);

    // ===============================================================
    // print from   N to 1  using backtracking
    // cout << "enter the value of n :" << endl;
    // int n;
    // cin >> n;
    // printNTo1Backtracking(1, n);

    // ===============================================================
    // print sum of 1 to N
    // cout << "enter the value of n :" << endl;
    // int n;
    // cin >> n;
    // int ans = sum(n);
    // cout << "sum is : " << ans << endl;

    // ===============================================================
    // print factorial of N
    // cout << "enter the value of n :" << endl;
    // int n;
    // cin >> n;
    // int ans = factorial(n);
    // cout << "factorial  is : " << ans << endl;

    // ===============================================================
    // reverse given array using recursion
    // int arr[] = {1, 2, 3, 4};
    // int size = 4;
    // reverseArray(arr, size, 0, size - 1);
    // reverseArrayVersion2(0, size, arr);
    // for (int i = 0; i < size; i++)
    //     cout << arr[i] << " ";

    // ===============================================================
    // check if give string is palindrome or not
    // cout << "enter string" << endl;
    // string str;
    // cin >> str;
    // bool ans = isPalindrome(str, 0);
    // if (ans)
    //     cout << "yes " << endl;
    // else
    //     cout << "no" << endl;

    // ===============================================================
    // find the nth fibonacci number
    cout << "enter number " << endl;
    int n;
    cin >> n;
    int ans = fibonacci(n);
    cout << n << " fibonacci number is : " << ans << endl;

    return 0;
}