#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string a, b;
        cin >> a >> b;

        array<bool, 26> has = { false, };
        for (char c : a)
            has[c - 'a'] = true;

        bool result = true;
        for (char c : b)
            result &= has[c - 'a'];

        if (result == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}