#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n;
        cin >> n;

        int result = (2 * n * n * n + 6 * n * n + 4 * n) / 12;
        printf("%d: %d %d\n", t, n, result);
    }
}