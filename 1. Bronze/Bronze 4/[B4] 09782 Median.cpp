#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int tc = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        vector<int> d(n);
        for (int i = 0; i < n; i++)
            cin >> d[i];

        float mid = (n % 2 == 1 ? d[n / 2] : (d[n / 2] + d[n / 2 - 1]) / 2.0);
        printf("Case %d: %.1f\n", ++tc, mid);
    }
}