#include <iostream>
#include <cstdio>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        long long n, k, s;
        cin >> n >> k >> s;

        long long result = min(k + n, 2 * k - s + n - s);
        printf("Case #%d: %lld\n", t, result);
    }
}