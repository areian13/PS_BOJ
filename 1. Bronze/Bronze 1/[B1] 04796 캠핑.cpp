#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int l, p, v;
        cin >> l >> p >> v;

        if (l == 0 && p == 0 && v == 0)
            break;

        int result = l * (v / p) + min(v % p, l);
        printf("Case %d: %d\n", ++tc, result);
    }
}