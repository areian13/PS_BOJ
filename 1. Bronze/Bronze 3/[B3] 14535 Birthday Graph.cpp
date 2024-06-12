#include <iostream>
#include <cstdio>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MONTHS 12

int main()
{
    FastIO;

    array<string, MONTHS> month = { "Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
    int tc = 0;
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            break;

        array<int, MONTHS> cnt = { 0, };

        for (int i = 0; i < n; i++)
        {
            int d, m, y;
            cin >> d >> m >> y;
            cnt[m - 1]++;
        }

        printf("Case #%d:\n", ++tc);
        for (int i = 0; i < MONTHS; i++)
        {
            printf("%s:", month[i].c_str());
            for (int j = 0; j < cnt[i]; j++)
                printf("*");
            printf("\n");
        }
    }
}