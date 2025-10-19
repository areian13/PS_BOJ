#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> r(5'000 + 1, 0);
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;

            if (a > b) swap(a, b);
            for (int j = a; j <= b; j++)
                r[j]++;
        }

        int p;
        cin >> p;

        printf("Case #%d: ", tc);
        for (int i = 0; i < p; i++)
        {
            int c;
            cin >> c;
            printf("%d ", r[c]);
        }
        printf("\n");
    }
}