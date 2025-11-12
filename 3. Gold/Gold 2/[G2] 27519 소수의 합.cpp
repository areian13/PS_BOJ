#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 100'000;
const int MOD = 1'000'000'007;

vector<int> primes;
void MakePrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= n; i++)
    {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= n; j += i)
            isPrime[j] = false;
    }

    for (int i = 0; i <= n; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }
}

int main()
{
    FastIO;

    MakePrimes(MAX);
    vector<int> dp(MAX + 1, 0);
    dp[0] = 1;
    for (int p : primes)
    {
        for (int i = p; i <= MAX; i++)
            dp[i] += dp[i - p], dp[i] %= MOD;
    }

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        cout << dp[n] << '\n';
    }
}