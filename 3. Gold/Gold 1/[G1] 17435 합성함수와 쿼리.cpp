#include <iostream>
#include <bit>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 500'000u
const int MAX_D = bit_width(MAX);

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
            f[i][j] = f[f[i][j - 1]][j - 1];
    }

    int QC;
    cin >> QC;

    for (int qc = 1; qc <= QC; qc++)
    {
        int n, x;
        cin >> n >> x;

        for (int j = 0; j < MAX_D; j++)
        {
            if (n & (1 << j))
                x = f[x][j];
        }

        cout << x << '\n';
    }
}