#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'003;

typedef vector<vector<int>> Matrix;
void init(Matrix& mat, int n)
{
    mat.resize(n, vector<int>(n, 0));
}
inline Matrix operator* (const Matrix& a, const Matrix& b)
{
    int n = a.size();

    Matrix c;
    init(c, n);
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

    Matrix result;
    init(result, n);
    for (int i = 0; i < n; i++)
        result[i][i] = 1;

    while (m)
    {
        if (m & 1) result = result * a;
        m >>= 1, a = a * a;
    }
    return result;
}

int main()
{
    FastIO;

    int n, s, e, t;
    cin >> n >> s >> e >> t;
    s--, e--;

    Matrix mat;
    init(mat, n * 5);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;

            if (c == '0')
                continue;

            int d = c - '0';
            for (int k = 0; k < d - 1; k++)
                mat[i * 5 + k][i * 5 + k + 1] = 1;
            mat[i * 5 + d - 1][j * 5] = 1;
        }
    }

    mat = Pow(mat, t);
    cout << mat[s * 5][e * 5] << '\n';
}