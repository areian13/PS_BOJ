#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    for (int tc = 1; tc <= n; tc++)
    {
        int m;
        cin >> m;

        vector<int> result = { 0,0 };
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;

            if (a == b)
                continue;
            if (abs(a - b) == 1)
                result[a > b] += (a + b) * (min(a, b) == 1 ? 2 : 1);
            else
                result[a < b] += max(a, b);
        }
        printf("Game %d: Tessa %d Danny %d\n", tc, result[0], result[1]);
    }
}