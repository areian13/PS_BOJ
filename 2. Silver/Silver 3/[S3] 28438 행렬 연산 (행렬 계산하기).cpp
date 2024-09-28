#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> mat(n + 1, vector<int>(m + 1, 0));
    while (q--)
    {
        int op, rc, v;
        cin >> op >> rc >> v;

        if (op == 1)
            mat[rc][0] += v;
        else
            mat[0][rc] += v;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            mat[i][j] += mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << mat[i][j] << ' ';
        cout << '\n';
    }
}