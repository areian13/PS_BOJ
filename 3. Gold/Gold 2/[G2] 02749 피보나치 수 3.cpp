#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000

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

int Fib(long long n)
{
    vector<vector<int>> pow = { {1,1},{1,0} };
    vector<vector<int>> result = { {1,0},{0,1} };
    while (n > 0)
    {
        if (n % 2 == 1)
            result = Dot(result, pow);
        pow = Dot(pow, pow);
        n /= 2;
    }

    return result[0][1];
}

int main()
{
    FastIO;

    long long n;
    cin >> n;

    int result = Fib(n);
    cout << result << '\n';
}