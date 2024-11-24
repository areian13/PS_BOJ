#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007

vector<vector<int>> Dot(const vector<vector<int>>& a, const vector<vector<int>>& b)
{
    int m = a.size();
    int n = b.size();
    int o = b[0].size();

    vector<vector<int>> result(m, vector<int>(o, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < o; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result[i][j] += (long long)a[i][k] * b[k][j] % MOD;
                result[i][j] %= MOD;
            }
        }
    }
    return result;
}

vector<vector<int>> Pow(vector<vector<int>>& matrix, int r)
{
    int n = matrix.size();

    vector<vector<int>> result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        result[i][i] = 1;

    while (r > 0)
    {
        if (r % 2 == 1)
            result = Dot(result, matrix);
        matrix = Dot(matrix, matrix);
        r /= 2;
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;

        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }

    int d;
    cin >> d;

    int result = Pow(matrix, d)[0][0];
    cout << result << '\n';
}