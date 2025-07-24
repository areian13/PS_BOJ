#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

double Avg(int start, int end, vector<int>& preSum)
{
    return (double)(preSum[end] - preSum[start - 1]) / (end - start + 1);
}

double Error(int start, int end, vector<vector<double>>& errorDP, vector<int>& preSum)
{
    if (errorDP[start][end] != -1.0)
        return errorDP[start][end];

    double avg = Avg(start, end, preSum);
    double result = 0;
    for (int i = start; i <= end; i++)
        result += pow(preSum[i] - preSum[i - 1] - avg, 2);
    return errorDP[start][end] = result;
}

double MinError(int k, double sum, int b, int n,
    vector<int>& preSum, vector<vector<double>>& dp, vector<vector<double>>& errorDP)
{
    if (k > n)
        return dp[n][b] = sum;

    if (dp[k][b] != -1.0)
        return dp[k][b];

    if (b == 1 || k == n)
    {
        double error = Error(k, n, errorDP, preSum);
        return dp[k][b] = sum + error;
    }

    double result = DBL_MAX;
    for (int i = k; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            double error = Error(i, j, errorDP, preSum);
            result = min(result, MinError(j + 1, sum + error, b - 1, n, preSum, dp, errorDP));
        }
    }
    return dp[k][b] = result;
}

int main()
{
    FastIO;

    int b, n;
    cin >> b >> n;

    vector<int> preSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int f;
        cin >> f;

        preSum[i] = preSum[i - 1] + f;
    }

    vector<vector<double>> dp(n + 1, vector<double>(b + 1, -1.0));
    vector<vector<double>> errorDP(n + 1, vector<double>(n + 1, -1.0));

    double result = MinError(1, 0.0, b, n, preSum, dp, errorDP);
    cout << result << '\n';
}