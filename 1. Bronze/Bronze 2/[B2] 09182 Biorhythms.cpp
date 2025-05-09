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
        int p, e, i, d;
        cin >> p >> e >> i >> d;

        if (p == -1 && e == -1 && i == -1 && d == -1)
            break;

        int result = d + 1;
        while ((result - p) % 23 != 0 || 
            (result - e) % 28 || 
            (result - i) % 33 != 0)
            result++;

        printf("Case %d: the next triple peak occurs in %d days.\n", ++tc, result - d);
    }
}