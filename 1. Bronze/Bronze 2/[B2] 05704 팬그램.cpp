#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsPangram(string& s)
{
    array<bool, 26> has = { false, };
    for (char c : s)
    {
        if (c != ' ')
            has[c - 'a'] = true;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!has[i])
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    while (true)
    {
        string s;
        getline(cin, s);

        if (s == "*")
            break;

        bool result = IsPangram(s);
        if (result == true)
            cout << 'Y' << '\n';
        else
            cout << 'N' << '\n';
    }
}