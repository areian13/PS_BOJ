#include <iostream>
#include <cstdio>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    double w, l, d;
    cin >> w >> l >> d;

    vector<vector<double>> dp(21, vector<double>(62, 0));
    dp[0][40] = 1;
    for (int i = 1; i <= 20; i++)
    {
        auto p = dp[i - 1];
        for (int j = 20; j <= 60; j++)
            dp[i][j] = p[j - 1] * w + p[j] * d + p[j + 1] * l;
    }

    for (int i = 20; i <= 60;)
    {
        double sum = 0;
        for (int j = 0; j < 10; j++)
            sum += dp[20][i++];
        printf("%.8lf\n", sum);
    }
}