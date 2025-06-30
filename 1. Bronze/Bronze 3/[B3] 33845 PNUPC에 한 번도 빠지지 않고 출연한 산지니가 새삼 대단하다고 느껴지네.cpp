#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string NoS(string& s, string& t)
{
    array<bool, 26> has = { false, };
    for (char c : s)
        has[c - 'a'] = true;

    string result = "";
    for (char c : t)
    {
        if (!has[c - 'a'])
            result += c;
    }
    return result;
}

int main()
{
    FastIO;

    string s, t;
    cin >> s >> t;

    string result = NoS(s, t);
    cout << result << '\n';
}