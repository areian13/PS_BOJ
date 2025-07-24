#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Matrix
{
    int r, c;
};

void MCM(vector<Matrix>& matrix, vector<vector<int>>& dp)
{
    int n = matrix.size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            int a = j;
            int b = i + j;

            if (a == b)
                continue;

            dp[a][b] = INT_MAX;
            for (int k = a; k < b; k++)
                dp[a][b] = min(dp[a][b], dp[a][k] + dp[k + 1][b] + (matrix[a].r * matrix[k].c * matrix[b].c));
        }
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Matrix> matrix(n);
    for (int i = 0; i < n; i++)
        cin >> matrix[i].r >> matrix[i].c;

    vector<vector<int>> dp(n, vector<int>(n, 0));
    MCM(matrix, dp);

    int result = dp[0][n - 1];
    cout << result << '\n';
}