#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void Flip(int i, int j, vector<vector<bool>>& a)
{
    for (int dr = -1; dr <= +1; dr++)
    {
        for (int dc = -1; dc <= +1; dc++)
            a[i + dr][j + dc] = !a[i + dr][j + dc];
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> a(n, vector<bool>(m)), b(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char t;
            cin >> t;

            a[i][j] = t - '0';
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char t;
            cin >> t;

            b[i][j] = t - '0';
        }
    }

    int result = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < m - 1; j++)
        {
            if (a[i - 1][j - 1] != b[i - 1][j - 1])
            {
                Flip(i, j, a);
                result++;
            }
        }
    }

    bool isSame = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            isSame &= (a[i][j] == b[i][j]);
    }

    if (isSame)
        cout << result << '\n';
    else
        cout << -1 << '\n';
}