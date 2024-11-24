#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000

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
                result[i][j] += (a[i][k] * b[k][j]) % MOD;
            result[i][j] %= MOD;

        }
    }
    return result;
}

vector<vector<int>> Pow(vector<vector<int>>& matrix, long long b)
{
    if (b == 1)
        return matrix;

    vector<vector<int>> result = Pow(matrix, b / 2);
    result = Dot(result, result);
    if (b % 2 == 1)
        result = Dot(result, matrix);
    return result;
}

int main()
{
    FastIO;

    int n;
    long long b;
    cin >> n >> b;

    vector<vector<int>> matrix(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> matrix[i][j];
    }

    vector<vector<int>> result = Pow(matrix, b);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << result[i][j] % MOD << ' ';
        cout << '\n';
    }
}