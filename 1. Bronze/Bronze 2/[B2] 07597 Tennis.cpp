#include <iostream>
#include <string>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (s == "#")
            break;

        array<int, 2> result = { 0,0 };
        array<int, 2> cnt = { 0,0 };
        for (char c : s)
        {
            int i = (c == 'B'), j = !i;
            cnt[i]++;

            if (cnt[i] >= 4 && abs(cnt[i] - cnt[j]) >= 2)
            {
                result[i]++;
                cnt = { 0,0 };
            }
        }

        cout << 'A' << ' ' << result[0] << ' ';
        cout << 'B' << ' ' << result[1] << '\n';
    }
}