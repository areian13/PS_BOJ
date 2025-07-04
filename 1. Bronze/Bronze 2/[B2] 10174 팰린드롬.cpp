#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsAlpha(char c)
{
    c |= 32;
    return 'a' <= c && c <= 'z';
}
bool IsPalin(string& s)
{
    int n = s.size();

    for (int i = 0; i < n / 2; i++)
    {
        char a = s[i];
        char b = s[n - 1 - i];
        if (a == b)
            continue;
        if (!IsAlpha(a) || !IsAlpha(b))
            return false;
        if ((a | 32) != (b | 32))
            return false;
    }
    return true;
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

        bool result = IsPalin(s);
        if (result == true)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}