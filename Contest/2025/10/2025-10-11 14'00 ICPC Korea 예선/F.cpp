#include <bits/stdc++.h>

using namespace std;

string f(string& s)
{
    int n = s.size();
    string r = "";
    for (int i = 0; i < n;)
    {
        int cnt = 1;
        while (i + cnt < n && s[i] == s[i + cnt])
            cnt++;
        if (cnt >= 10)
            return "-1";

        r += to_string(cnt) + s[i];
        i += cnt;
    }
    return r;
}

string fr(string& s)
{
    int n = s.size();
    if (n & 1)
        return "-1";

    string r = "";
    for (int i = 0; i < n; i+=2)
    {
        for (int j = 0; j < s[i] - '0'; j++)
        {
            r += s[i + 1];
        }
    }
    if (s != f(r) || r[0] == '0')
        return "-1";
    return r;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

    string s;
    cin >> s;

    string result = fr(s);
    cout << result << '\n';
}