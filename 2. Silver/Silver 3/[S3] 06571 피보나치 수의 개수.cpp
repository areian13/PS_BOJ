#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool le(string& a, string& b)
{
    int n = a.size(), m = b.size();

    if (n != m)
        return n < m;

    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i])
            return false;
        if (a[i] < b[i])
            return true;
    }
    return true;
}

string add(string a, string b)
{
    if (le(b, a))
        swap(a, b);

    int n = a.size(), m = b.size();

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int rem = 0;
    string c = "";
    for (int i = 0; i < n; i++)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + rem;
        c += sum % 10 + '0';
        rem = sum / 10;
    }
    for (int i = n; i < m; i++)
    {
        int sum = (b[i] - '0') + rem;
        c += sum % 10 + '0';
        rem = sum / 10;
    }
    if (rem != 0)
        c += rem + '0';
    reverse(c.begin(), c.end());

    return c;
}

int main()
{
    FastIO;

    string MAX(101, '0');
    MAX[0] = '1';

    vector<string> dp = { "1","2" };
    while (le(dp.back(), MAX))
        dp.push_back(add(dp[dp.size() - 1], dp[dp.size() - 2]));

    while (true)
    {
        string a, b;
        cin >> a >> b;

        if (a == "0" && b == "0")
            break;

        int result = 0;
        for (int i = 0; le(dp[i], b); i++)
            result += le(a, dp[i]);
        cout << result << '\n';
    }
}