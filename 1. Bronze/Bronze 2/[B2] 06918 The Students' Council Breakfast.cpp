#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int p, g, r, o, m;
    cin >> p >> g >> r >> o >> m;

    int cnt = 0;
    int minT = INT_MAX;
    for (int i = 0; i <= m / p; i++)
    {
        for (int j = 0; j <= m / g; j++)
        {
            for (int k = 0; k <= m / r; k++)
            {
                for (int l = 0; l <= m / o; l++)
                {
                    if (i * p + j * g + k * r + l * o == m)
                    {
                        printf("# of PINK is %d # of GREEN is %d # of RED is %d # of ORANGE is %d\n",
                            i, j, k, l);
                        cnt++;
                        minT = min(minT, i + j + k + l);
                    }
                }
            }
        }
    }

    printf("Total combinations is %d.\n", cnt);
    printf("Minimum number of tickets to print is %d.\n", minT);
}