#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'007;

typedef vector<vector<int>> Matrix;
inline Matrix operator* (const Matrix& a, const Matrix& b)
{
    int n = a.size();

    Matrix c(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            for (int j = 0; j < n; j++)
                c[i][j] = (c[i][j] + 1LL * a[i][k] * b[k][j]) % MOD;
        }
    }
    return c;
}

Matrix Pow(Matrix a, int m)
{
    int n = a.size();

    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        result[i][i] = 1;

    while (m)
    {
        if (m & 1) result = result * a;
        m >>= 1, a = a * a;
    }
    return result;
}

Matrix RBC(vector<Matrix>& map, int d)
{
    int t = map.size();
    int n = map[0].size();

    Matrix result(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++)
        result[i][i] = 1;

    for (int i = 0; i < t; i++)
        result = result * map[i];

    result = Pow(result, d / t);
    for (int i = 0; i < d % t; i++)
        result = result * map[i];
    return result;
}

int main()
{
    FastIO;

    int t, n, d;
    cin >> t >> n >> d;

    vector<Matrix> map(t, Matrix(n, vector<int>(n, 0)));
    for (int k = 0; k < t; k++)
    {
        int m;
        cin >> m;

        for (int i = 0; i < m; i++)
        {
            int u, v, c;
            cin >> u >> v >> c;
            u--, v--;
            map[k][u][v] += c;
        }
    }

    Matrix result = RBC(map, d);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << result[i][j] << ' ';
        cout << '\n';
    }
}