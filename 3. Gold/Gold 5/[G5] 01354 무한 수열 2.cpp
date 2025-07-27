#include <iostream>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int p, q, x, y;
unordered_map<long long, long long> dp;

long long A(long long i)
{
    if (i <= 0)
        return 1;
    if (dp[i] != 0)
        return dp[i];

    return dp[i] = A(i / p - x) + A(i / q - y);
}

int main()
{
    FastIO;

    long long n;
    cin >> n >> p >> q >> x >> y;

    long long result = A(n);
    cout << result << '\n';
}