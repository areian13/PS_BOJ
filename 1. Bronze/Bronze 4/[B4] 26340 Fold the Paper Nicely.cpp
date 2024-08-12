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

    while (tc--)
    {
        int a, b, n;
        cin >> a >> b >> n;

        printf("Data set: %d %d %d\n", a, b, n);
        for (int i = 0; i < n; i++)
        {
            if (a > b)
                a /= 2;
            else
                b /= 2;
        }
        printf("%d %d\n\n", max(a, b), min(a, b));
    }
}