#include <iostream>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        string s;
        cin >> s;

        int n = s.size();
        int result = n + 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 6; i + j <= n; j++)
            {
                array<bool, 3> has = { false, };
                for (char c : s.substr(i, j))
                {
                    has[0] |= ('A' <= c && c <= 'Z');
                    has[1] |= ('a' <= c && c <= 'z');
                    has[2] |= ('0' <= c && c <= '9');
                }

                if (has[0] && has[1] && has[2])
                    result = min(result, j);
            }
        }
        if (result == n + 1)
            cout << 0 << '\n';
        else
            cout << result << '\n';
    }
}