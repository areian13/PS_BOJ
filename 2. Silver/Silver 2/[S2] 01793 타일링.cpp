#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 250

struct str_int
{
    string v;

    friend str_int operator + (str_int a, str_int b)
    {
        if (a.v.size() > b.v.size())
            swap(a, b);

        reverse(a.v.begin(), a.v.end());
        reverse(b.v.begin(), b.v.end());

        int n = a.v.size();
        int m = b.v.size();

        string c;
        int i = 0, r = 0;
        while (i < n)
        {
            int s = ((a.v[i] - '0') + (b.v[i] - '0')) + r;
            c += s % 10 + '0';
            r = s / 10;
            i++;
        }
        while (i < m)
        {
            int s = (b.v[i] - '0') + r;
            c += s % 10 + '0';
            r = s / 10;
            i++;
        }
        if (r != 0)
            c += r + '0';

        reverse(c.begin(), c.end());
        return str_int(c);
    }
};

int main()
{
    FastIO;

    vector<str_int> dp(MAX + 1);
    dp[0] = dp[1] = (str_int)"1";
    for (int i = 2; i <= MAX; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 2];

    while (true)
    {
        int n;
        cin >> n;

        if (cin.eof())
            break;

        cout << dp[n].v << '\n';
    }
}