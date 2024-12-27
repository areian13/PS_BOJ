#include <iostream>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, n;
    cin >> a >> b >> n;

    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int c, k;
        cin >> c >> k;

        bool hasA = false;
        bool hasB = false;
        for (int i = 0; i < k; i++)
        {
            int u;
            cin >> u;

            hasA |= (u == a);
            hasB |= (hasA && u == b);
        }

        if (hasA && hasB)
            result = min(result, c);
    }

    if (result == INT_MAX)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}