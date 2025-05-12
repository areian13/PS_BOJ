#include <iostream>
#include <cstdio>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        string a, b;
        cin >> n >> a >> b;

        int result = 0;
        for (int i = 0; i < n; i++)
            result += (a[i] != b[i]);
        printf("Case %d: %d\n", tc, result);
    }
}