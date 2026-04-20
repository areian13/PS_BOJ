#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string RL(string& s)
{
    int n = s.size();
    string result = "";
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        while (i + 1 < n && s[i] == s[i + 1])
            i++, cnt++;
        result += to_string(cnt) + ' ' + s[i] + ' ';
    }
    return result;
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

        string result = RL(s);
        cout << result << '\n';
    }
}