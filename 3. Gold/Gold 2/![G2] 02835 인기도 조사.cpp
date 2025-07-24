#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_SEC (24 * 60 * 60)

int main()
{
    FastIO;

    int n;
    scanf("%d", &n);

    array<int, MAX_SEC> cnt = { 0, };
    for (int i = 0; i < n; i++)
    {
        int sh, sm, ss, eh, em, es;
        scanf("%d:%d:%d - %d:%d:%d", &sh, &sm, &ss, &eh, &em, &es);

        int sSec = sh * 24 + sm * 60 + ss;
        int eSec = eh * 24 + em * 60 + es + MAX_SEC;

        for (int t = sSec; t <= eSec; t++)
            cnt[t % MAX_SEC]++;
    }

    array<int, MAX_SEC + 1> preSum = { 0, };
    for (int i = 1; i <= MAX_SEC; i++)
        preSum[i] = preSum[i - 1] + cnt[i - 1];

    int q;
    scanf("%d", &q);

    while (q--)
    {
        int sh, sm, ss, eh, em, es;
        scanf("%d:%d:%d - %d:%d:%d", &sh, &sm, &ss, &eh, &em, &es);

        int sSec = sh * 24 + sm * 60 + ss;
        int eSec = eh * 24 + em * 60 + es;

        if (sSec <= eSec)
        {
            double result = (double)(preSum[eSec + 1] - preSum[sSec]) / (eSec - sSec + 1);
            printf("%.6lf\n", result);
        }
    }
}