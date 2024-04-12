#include <iostream>
#include <vector>
using namespace std;

int countDigits(int n)
{
    int count = 0;
    while (n > 0)
    {

        count++;
        n = n / 10;
    }

    return count;
}

int reverseNum(int n)
{
    int reverseNumber = 0;
    while (n > 0)
    {
        int lastDigit = n % 10;
        reverseNumber = (reverseNumber * 10) + lastDigit;
        n = n / 10;
    }
    return reverseNumber;
}

bool isPalindrome(int n)
{
    int reverseNumber = reverseNum(n);
    if (reverseNumber == n)
        return true;
    else
        return false;
}

bool isArmstrongNum(int n)
{
    int dupN = n;
    int lastDigit = 0;
    int sum = 0;
    while (n > 0)
    {
        lastDigit = n % 10;
        sum = sum + (lastDigit * lastDigit * lastDigit);
        n = n / 10;
    }
    if (sum == dupN)
        return true;
    else
        return false;
}

vector<int> printAllDivisors(int n)
{
    vector<int> v;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            v.push_back(i);
            if ((n / i) != i)

                v.push_back(n / i);
        }
    }
    sort(v.begin(), v.end());
    return v;
}

bool checkPrime(int n)
{
    int count = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            count++;
            if ((n / i) != i)
                count++;
        }
    }
    cout << " count : " << count << endl;
    if (count == 2)
        return true;
    else
        return false;
}

int gcd(int n1, int n2)
{
    int ans = 0;
    for (int i = 0; i < min(n1, n2); i++)
    {
        if ((n1 % i == 0) && (n2 % i == 0))
        {
            ans = i;
        }
    }
    return ans;
}

int gcdVersion2(int n1, int n2)
{
    while (n1 > 0 && n2 > 0)
    {
        if (n1 > n2)
            n1 = n1 % n2;
        else
            n2 = n2 % n1;
    }

    if (n1 == 0)
        return n2;
    return n1;
}

int main()

{

    //=================================================================
    // count number of digits
    // int n;
    // cout << "enter your number" << endl;
    // cin >> n;

    // int ans = countDigits(n);
    // cout << "no. of digits are :" << ans << endl;

    //=================================================================
    // reverse a number
    // int n;
    // cout << "enter your number" << endl;
    // cin >> n;

    // int ans = reverseNum(n);
    // cout << "revers of " << n << " is : " << ans << endl;

    //=================================================================
    // check palindorome number
    // int n;
    // cout << "enter your number" << endl;
    // cin >> n;

    // bool ans = isPalindrome(n);
    // if (ans)
    //     cout << n << " is palindrome" << endl;
    // else
    //     cout << n << " is not palindrome" << endl;

    //=================================================================
    // check armstrong number
    // int n;
    // cout << "enter your number" << endl;
    // cin >> n;

    // bool ans = isArmstrongNum(n);
    // if (ans)
    //     cout << n << " is armstrong number" << endl;
    // else
    //     cout << n << " is not armstrong number" << endl;

    //==================================================================
    // find all divisor of number
    // int n;
    // cout << "enter your number" << endl;
    // cin >> n;
    // vector<int> ans = printAllDivisors(n);
    // for (int i = 0; i < ans.size(); i++)
    //     cout << ans[i] << " ";

    //==================================================================
    // check prime
    // int n;
    // cout << "enter your number" << endl;
    // cin >> n;
    // bool ans = checkPrime(n);
    // if (ans)
    //     cout << n << " is prime " << endl;
    // else
    //     cout << n << " is not prime" << endl;

    //==================================================================
    // find GCD of two numbers
    // int n1;
    // int n2;
    // cout << "enter first number" << endl;
    // cin >> n1;
    // cout << "enter second number" << endl;
    // cin >> n2;
    // int ans2 = gcd(n1 , n2)
    // int ans = gcdVersion2(n1, n2);
    // cout << "gdc of " << n1 << " and " << n2 << " is :" << ans << endl;

    return 0;
}