#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string JustAdd(string& a, string& b)
{
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    int n = max(a.size(), b.size());
    string result = "";
    for (int i = 0; i < n; i++)
    {
        if (i >= a.size())
            result += b[i];
        else if (i >= b.size())
            result += a[i];
        else
        {
            int v = (a[i] - '0') + (b[i] - '0');
            do
            {
                result += v % 10 + '0';
                v /= 10;
            } while (v > 0);
        }
    }
    reverse(result.begin(), result.end());
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    return result;
}

int main()
{
    FastIO;

    string a, b;
    cin >> a >> b;

    string result = JustAdd(a, b);
    cout << result << '\n';
}