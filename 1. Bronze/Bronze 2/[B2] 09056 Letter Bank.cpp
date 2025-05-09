#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool AIsBankOfB(string& a, string& b)
{
    array<bool, 26> hasA = { false, };
    for (char c : b)
        hasA[c - 'A'] = true;

    array<bool, 26> hasB = { false, };
    for (char c : a)
        hasB[c - 'A'] = true;

    for (int i = 0; i < 26; i++)
    {
        if (hasA[i] != hasB[i])
            return false;
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
        string a, b;
        cin >> a >> b;

        bool result = AIsBankOfB(a, b);
        if (result == true)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
    }
}