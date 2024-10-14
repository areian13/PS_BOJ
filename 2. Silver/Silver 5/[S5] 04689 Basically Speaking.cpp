#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int ctoi(char c)
{
    if (('0' <= c && c <= '9'))
        return c - '0';
    return c - 'A' + 10;
}

char itoc(int n)
{
    if (0 <= n && n <= 9)
        return n + '0';
    return n - 10 + 'A';
}

int BaseToDec(string& n, int b)
{
    int result = 0;
    int d = n.size();
    int power = 1;
    for (int i = d - 1; i >= 0; i--)
    {
        result += ctoi(n[i]) * power;
        power *= b;
    }
    return result;
}

string DecToBase(int n, int b)
{
    string result = "";
    do
    {
        result += itoc(n % b);
        n /= b;
    } while (n > 0);

    reverse(result.begin(), result.end());

    return result;
}

string Convert(string n, int fd, int td)
{
    return DecToBase(BaseToDec(n, fd), td);
}

int main()
{
    FastIO;

    while (true)
    {
        string n;
        int fd, td;
        cin >> n >> fd >> td;

        if (cin.eof())
            break;

        string result = Convert(n, fd, td);
        printf("%7s\n", result.size() > 7 ? "ERROR" : result.c_str());
    }
}