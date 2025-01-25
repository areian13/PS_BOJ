#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX_N 500'000
#define MAX_D 19

int main()
{
    FastIO;

    int m;
    cin >> m;

    vector<array<int, MAX_D>> f(m + 1);
    for (int i = 1; i <= m; i++)
        cin >> f[i][0];

    for (int j = 1; j < MAX_D; j++)
    {
        for (int i = 1; i <= m; i++)
            f[i][j] = f[ f[i][j - 1] ][j - 1];
    }

    int query;
    cin >> query;

    for (int q = 1; q <= query; q++)
    {
        int n, x;
        cin >> n >> x;

        for (int i = 0; i < MAX_D; i++)
        {
            if (n & (1 << i))
            {
                x = f[x][i];
                n -= 1 << i;
            }
        }

        cout << x << '\n';
    }
}