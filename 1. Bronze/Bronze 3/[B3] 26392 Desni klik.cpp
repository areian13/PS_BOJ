#include <iostream>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc, r, s;
    cin >> tc >> r >> s;

    while (tc--)
    {
        int minValue = INT_MAX;
        int maxValue = 0;
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < s; j++)
            {
                char c;
                cin >> c;

                if (c == '#')
                {
                    minValue = min(minValue, i);
                    maxValue = max(maxValue, i);
                }
            }
        }

        int result = maxValue - minValue;
        cout << result << '\n';
    }
}