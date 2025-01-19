#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string DecToBase(int n, int b)
{
    const static string d = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string result = "";
    do
    {
        result += d[n % b];
        n /= b;
    } while (n > 0);

    reverse(result.begin(), result.end());
    return result;
}

int ctod(char c)
{
    if ('0' <= c && c <= '9')
        return c - '0';
    return c - 'A' + 10;
}

int StrSum(string& s)
{
    int result = 0;
    for (char c : s)
        result += ctod(c);
    return result;
}

bool IsSpecial(int n)
{
    string dec = DecToBase(n, 10);
    string doz = DecToBase(n, 12);
    string hex = DecToBase(n, 16);

    return StrSum(dec) == StrSum(doz) && StrSum(doz) == StrSum(hex);
}

int main()
{
    FastIO;

    for (int n = 1000; n <= 9999; n++)
    {
        if (IsSpecial(n))
            cout << n << '\n';
    }
}