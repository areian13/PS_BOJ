#include <iostream>
#include <cstdio>
#include <vector>
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
        int n, p, q;
        cin >> n >> p >> q;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        int result = 0;
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (sum + a[i] <= q)
            {
                sum += a[i];
                result++;
            }
            else
                break;
        }

        result = min(result, p);
        printf("Case %d: %d\n", tc, result);
    }
}