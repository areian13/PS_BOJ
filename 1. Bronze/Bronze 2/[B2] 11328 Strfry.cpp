#include <iostream>
#include <string>
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

        array<int, 26> aCnt = { 0, }, bCnt = { 0, };
        for (char c : a)
            aCnt[c - 'a']++;
        for (char c : b)
            bCnt[c - 'a']++;

        bool result = true;
        for (int i = 0; i < 26; i++)
            result &= (aCnt[i] == bCnt[i]);

        if (result)
            cout << "Possible" << '\n';
        else
            cout << "Impossible" << '\n';
    }
}