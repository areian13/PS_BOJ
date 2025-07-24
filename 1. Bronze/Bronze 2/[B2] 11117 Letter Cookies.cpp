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

    for (int i = 1; i <= TC; i++)
    {
        string s;
        int n;
        cin >> s >> n;

        array<int, 26> cnt = { 0, };
        for (char c : s)
            cnt[c - 'A']++;

        for (int i = 0; i < n; i++)
        {
            string k;
            cin >> k;

            array<int, 26> cntK = { 0, };
            for (char c : k)
                cntK[c - 'A']++;

            bool result = true;
            for (int i = 0; i < 26; i++)
                result &= cntK[i] <= cnt[i];

            if (result)
                cout << "YES" << '\n';
            else
                cout << "NO" << '\n';
        }
    }
}