#include <iostream>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long p, q;
unordered_map<long long, long long > dp;

long long A(long long i)
{
    if (i <= 0)
        return 1;
    if (dp[i] != 0)
        return dp[i];

    return dp[i] = A(i / p) + A(i / q);
}

int main()
{
    FastIO;

    long long n;
    cin >> n >> p >> q;

    long long result = A(n);
    cout << result << '\n';
}