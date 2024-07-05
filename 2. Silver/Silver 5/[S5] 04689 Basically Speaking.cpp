#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 7

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
    int k = 1;
    for (int i = d - 1; i >= 0; i--)
    {
        result += ctoi(n[i]) * k;
        k *= b;
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

        string result = DecToBase(BaseToDec(n, fd), td);

        if (result.size() > SIZE)
            result = "ERROR";

        cout << string(SIZE - result.size(), ' ') << result << '\n';
    }
}