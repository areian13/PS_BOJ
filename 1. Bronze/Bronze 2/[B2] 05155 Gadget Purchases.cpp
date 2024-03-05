#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Machine
{
    int p, c, u, r, k;
};

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++)
    {
        int n, m;
        cin >> n >> m;

        vector<Machine> machine(m);
        vector<int> revenue(m, 0);
        for (int i = 0; i < m; i++)
        {
            int p, c, u, r;
            cin >> p >> c >> u >> r;

            machine[i] = { p,c,u,r,u };
            revenue[i] -= p;
        }

        for (int i = 0; i < n; i++)
        {
            int j;
            cin >> j;
            j--;

            revenue[j] += (machine[j].r - machine[j].c) * (machine[j].k > 0);
            machine[j].k = max(machine[j].k - 1, 0);
        }

        vector<int> result;
        for (int i = 0; i < m; i++)
        {
            if (revenue[i] > 0)
                result.push_back(i + 1);
        }

        printf("Data Set %d:\n", t);
        for (int j : result)
            printf("%d\n", j);
        printf("\n");
    }
}