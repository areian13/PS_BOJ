#include <iostream>
#include <string>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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

        array<int, 26> cnt = { 0, };
        for (char c : s)
        {
            if ('a' <= c && c <= 'z')
                cnt[c - 'a']++;
        }

        int maxCnt = *max_element(cnt.begin(), cnt.end());
        int result = -1;
        for (int i = 0; i < 26; i++)
        {
            if (cnt[i] == maxCnt)
            {
                if (result != -1)
                {
                    result = -1;
                    break;
                }
                result = i;
            }
        }

        if (result == -1)
            cout << '?' << '\n';
        else
            cout << (char)(result + 'a') << '\n';
    }
}