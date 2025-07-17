#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string MissingChars(string& s)
{
    array<bool, 26> has = { false, };
    for (char c : s)
    {
        c |= 32;

        if ('a' <= c && c <= 'z')
            has[c - 'a'] = true;
    }

    string result = "";
    for (int i = 0; i < 26; i++)
    {
        if (!has[i])
            result += i + 'a';
    }
    return result;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    cin.ignore();
    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        getline(cin, s);

        string result = MissingChars(s);
        if (result.empty())
            cout << "pangram" << '\n';
        else
            cout << "missing" << ' ' << result << '\n';
    }
}