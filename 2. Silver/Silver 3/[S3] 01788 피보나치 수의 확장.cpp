#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'000

int Fib(int n)
{
    array<int, 2> dp = { 0,1 };
    for (int i = 0; i < n; i++)
        dp[i % 2] = (dp[i % 2] + dp[(i + 1) % 2]) % MOD;
    return dp[n % 2];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int dir = (n == 0 ? 0 : (n < 0 && -n % 2 == 0 ? -1 : +1));
    array<int, 2> result = { dir,Fib(abs(n)) };
    cout << result[0] << '\n';
    cout << result[1] << '\n';
}