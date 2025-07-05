#include <iostream>
#include <cstdio>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Type(int ey, int by, int n)
{
    if (ey >= 2010 || by >= 1991)
        return 1;
    if (n >= 41)
        return -1;
    return 0;
}

int main()
{
    FastIO;

    int TC;
    scanf("%d", &TC);

    for (int tc = 1; tc <= TC; tc++)
    {
        char name[31] = { '\0', };
        int ey, em, ed, by, bm, bd, n;
        scanf("%s %d/%d/%d %d/%d/%d %d", &name, &ey, &em, &ed, &by, &bm, &bd, &n);

        int result = Type(ey, by, n);
        printf("%s %s\n", name, (result > 0 ? "eligible" : (result < 0 ? "ineligible" : "coach petitions")));
    }
}