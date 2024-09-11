#include <iostream>
#include <string>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SqrtStr(string& s)
{
    int n = s.size();

    for (int i = 1; i <= n; i++)
    {
        if (n % i != 0)
            continue;

        bool isPowStr = true;
        string sub = s.substr(0, i);
        for (int j = i; j < n; j += i)
        {
            if (s.substr(j, i) != sub)
            {
                isPowStr = false;
                break;
            }
        }
        if (isPowStr)
            return n / i;
    }
    return 1;
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == ".")
            break;

        int result = SqrtStr(s);
        cout << result << '\n';
    }
}