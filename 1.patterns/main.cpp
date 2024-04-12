#include <iostream>
using namespace std;

void pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern2(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void pattern3(int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1;
        }

        cout << endl;
    }
}

void pattern4(int n)
{
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < i + 1; j++)
        {
            cout << i + 1;
        }

        cout << endl;
    }
}

void pattern5(int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void pattern6(int n)
{

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n - i; j++)
        {
            cout << j + 1;
        }

        cout << endl;
    }
}

void pattern7(int n)
{

    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }
        // starts
        for (int k = 0; k < 2 * i + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern8(int n)
{

    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }
        // starts
        for (int k = 0; k < 2 * n - (2 * i + 1); k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern9(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - (i + 1); j++)
        {
            cout << " ";
        }

        for (int k = 0; k < (2 * i) + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            cout << " ";
        }

        for (int k = 0; k < (2 * n - 2 * i) - 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern10(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - (i + 1); j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern11(int n)
{
    for (int i = 0; i < n; i++)
    {
        int temp = 1;
        if (i % 2 == 0)
            temp = 1;
        else
            temp = 0;
        for (int j = 0; j < i + 1; j++)
        {
            cout << temp;
            temp = 1 - temp;
        }
        cout << endl;
    }
}

void pattern12(int n)
{
    for (int i = 0; i < n; i++)
    {

        // nums
        for (int j = 0; j < i + 1; j++)
        {
            cout << j + 1;
        }
        // stars
        for (int p = 0; p < 2 * n - 2 * (i + 1); p++)
        {
            cout << " ";
        }
        // nums
        for (int k = i + 1; k > 0; k--)
        {
            cout << k;
        }
        cout << endl;
    }
}

void pattern13(int n)
{

    int temp = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << temp++ << " ";
        }
        cout << endl;
    }
}

void pattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            char ch = 'A' + j;
            cout << ch;
        }
        cout << endl;
    }
}

void pattern15(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (char ch = 'A'; ch <= 'A' + (n - i - 1); ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
}

void pattern16(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + i;
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch;
        }
        cout << endl;
    }
}

void pattern17(int n)
{
    for (int i = 0; i < n; i++)
    {
        // spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << " ";
        }

        // chars
        char ch = 'A';
        int breakPoint = (2 * i + 1) / 2;
        for (int j = 0; j < 2 * i + 1; j++)
        {
            if (j >= breakPoint)
            {
                cout << ch--;
            }
            else
            {
                cout << ch++;
            }
        }
        cout << endl;
    }
}

void pattern18(int n)
{
    for (int i = 0; i < n; i++)
    {
        char ch = 'A' + (n - (i + 1));
        for (int j = 0; j < i + 1; j++)
        {
            cout << ch++;
        }
        cout << endl;
    }
}

void pattern19(int n)
{
    // upper half
    for (int i = 0; i < n; i++)
    {
        // star
        for (int j = 0; j < n - i; j++)
        {
            cout << "*";
        }
        // spaces
        for (int k = 0; k < 2 * i; k++)
        {
            cout << " ";
        }
        // star
        for (int l = 0; l < n - i; l++)
        {
            cout << "*";
        }
        cout << endl;
    }

    // lower half
    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        // spaces
        for (int k = 0; k < 2 * (n - i - 1); k++)
        {
            cout << " ";
        }
        // sars
        for (int l = 0; l < i + 1; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern20(int n)
{

    for (int i = 0; i < n; i++)
    {
        // stars
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        // spaces
        for (int k = 0; k < 2 * (n - i - 1); k++)
        {
            cout << " ";
        }
        // sars
        for (int l = 0; l < i + 1; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i++)
    {
        // star
        for (int j = 0; j < n - i - 1; j++)
        {
            cout << "*";
        }
        // spaces
        for (int k = 0; k < 2 * i + 2; k++)
        {
            cout << " ";
        }
        // star
        for (int l = 0; l < n - i - 1; l++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void pattern21(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == n - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
        cout << endl;
    }
}

void pattern22(int n)
{
    for (int i = 0; i < 2 * n - 1; i++)
    {
        for (int j = 0; j < 2 * n - 1; j++)
        {
            int top = i;
            int left = j;
            int right = (2 * n - 2) - j;
            int bottom = (2 * n - 2) - i;
            cout << (n - min(min(top, bottom), min(left, right)));
        }
        cout << endl;
    }
}

int main()
{

    int n;
    cin >> n;

    // pattern1(n);

    return 0;
}