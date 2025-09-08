#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int result = INT_MAX;
    for (int i = 0; i < m; i++)
    {
        int u, d;
        cin >> u >> d;

        int s = 1, e = n - 1;
        int p = n;
        while (s <= e)
        {
            int m = (s + e) / 2;

            if (1. * d / u < 1. * m / (n - m))
            {
                p = m;
                e = m - 1;
            }
            else
                s = m + 1;
        }
        result = min(result, p * u - (n - p) * d);
    }
    cout << result << '\n';
}