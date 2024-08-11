#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define DAY_MINUTE (24 * 60)

int main()
{
    FastIO;

    int minMinute = INT_MAX;
    int maxMinute = 0;
    for (int i = 0; i < 3; i++)
    {
        int h1, m1, h2, m2;
        cin >> h1 >> m1 >> h2 >> m2;

        int minute = ((h2 - h1) * 60 + (m2 - m1) + DAY_MINUTE) % DAY_MINUTE;

        minMinute = min(minMinute, minute);
        maxMinute = max(maxMinute, minute);
    }

    printf("%d:%02d\n", minMinute / 60, minMinute % 60);
    printf("%d:%02d\n", maxMinute / 60, maxMinute % 60);
}