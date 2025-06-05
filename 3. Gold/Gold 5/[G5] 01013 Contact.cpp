#include <iostream>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool Is100101(string s)
{
    reverse(s.begin(), s.end());
    while (!s.empty())
    {
        int n = s.size();
        if (n >= 2 && s[n - 1] == '0' && s[n - 2] == '1')
        {
            s.pop_back();
            s.pop_back();
            continue;
        }

        if (n >= 4 && s[n - 1] == '1' && s[n - 2] == '0' && s[n - 3] == '0')
        {
            s.pop_back();
            s.pop_back();
            s.pop_back();
        }
        else
            return false;

        while (!s.empty() && s.back() == '0')
            s.pop_back();
        if (s.empty())
            return false;
        int cnt = 0;
        while (!s.empty() && s.back() == '1')
        {
            s.pop_back();
            cnt++;
        }

        n = s.size();
        if (n >= 2 && cnt >= 2 && s[n - 1] == '0' && s[n - 2] == '0')
            s.push_back('1');
    }
    return true;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        cin >> s;

        bool result = Is100101(s);
        if (result == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}