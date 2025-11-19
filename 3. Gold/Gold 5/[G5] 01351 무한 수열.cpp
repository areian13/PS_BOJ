#include <iostream>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long A(long long n, long long p, long long q)
{
    static unordered_map<int, long long> dp;
    if (n == 0) return 1;
    if (dp.count(n) == 1) return dp[n];

    return dp[n] = A(n / p, p, q) + A(n / q, p, q);
}

int main()
{
    FastIO;

    long long n, p, q;
    cin >> n >> p >> q;

    long long result = A(n, p, q);
    cout << result << '\n';
}