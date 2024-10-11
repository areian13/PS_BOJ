#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ctoi(char c)
{
    if ('a' <= c && c <= 'z')
        return c - 'a' + 1;
    return c - 'A' + 27;
}

bool IsPrime(int n)
{
    if (n == 1)
        return true;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

bool IsPrimeWord(string& s)
{
    int sum = 0;
    for (char c : s)
        sum += ctoi(c);
    return IsPrime(sum);
}

int main()
{
    FastIO;

    string s;
    cin >> s;

    if (IsPrimeWord(s))
        printf("It is a prime word.\n");
    else
        printf("It is not a prime word.\n");
}