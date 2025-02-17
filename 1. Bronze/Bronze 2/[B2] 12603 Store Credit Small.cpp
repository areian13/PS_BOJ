#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int c, n;
        cin >> c >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        pair<int, int> result;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (p[i] + p[j] == c)
                    result = { i,j };
            }
        }
        printf("Case #%d: %d %d\n", tc, result.first + 1, result.second + 1);
    }
}