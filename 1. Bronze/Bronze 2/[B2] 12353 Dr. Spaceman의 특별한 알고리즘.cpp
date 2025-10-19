#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int TC;
    scanf("%d\n", &TC);

    for (int tc = 1; tc <= TC; tc++)
    {
        char c;
        int d1, d2, m1, m2;
        scanf("%c %d'%d\" %d'%d\"\n", &c, &d1, &d2, &m1, &m2);

        int d = d1 * 12 + d2;
        int m = m1 * 12 + m2;

        double result = (d + m + (c == 'B' ? +5 : -5)) / 2.;
        int l = ceil(result - 4), r = floor(result + 4);
        printf("Case #%d: %d'%d\" to %d'%d\"\n", tc, l / 12, l % 12, r / 12, r % 12);
    }
}