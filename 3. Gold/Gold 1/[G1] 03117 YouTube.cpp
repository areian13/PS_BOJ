#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define N_MAX 30

int main()
{
    FastIO;

    int n, k, m;
    cin >> n >> k >> m;

    vector<int> x(n);
    for (int i = 0; i < n; i++)
        cin >> x[i];

    vector<array<int, N_MAX>> f(k + 1);
    for (int i = 1; i <= k; i++)
        cin >> f[i][0];

    for (int j = 1; j < N_MAX; j++)
    {
        for (int i = 1; i <= k; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];
    }

    for (int i = 0; i < n; i++)
    {
        int M = m - 1;
        int X = x[i];

        for (int j = N_MAX - 1; j >= 0; j--)
        {
            if (M >= 1 << j)
            {
                M -= 1 << j;
                X = f[X][j];
            }
        }
        cout << X << '\n';
    }
}