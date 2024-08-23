#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int ti = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
        }

        printf("Case %d: Sorting... done!\n", ++ti);
    }
}