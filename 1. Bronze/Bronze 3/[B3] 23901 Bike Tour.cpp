#include <iostream>
#include <cstdio>
#include <vector>

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

        vector<int> h(n);
        for (int i = 0; i < n; i++)
            cin >> h[i];

        int result = 0;
        for (int i = 1; i < n - 1; i++)
            result += (h[i - 1] < h[i] && h[i] > h[i + 1]);
        printf("Case #%d: %d\n", t, result);
    }
}