#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 45

int Fib(int k)
{
    static vector<int> dp(MAX + 1, -1);

    if (k <= 1)
        return dp[k] = k;
    if (dp[k] != -1)
        return dp[k];
    return dp[k] = Fib(k - 1) + Fib(k - 2);
}

int main()
{
    FastIO;

    int k;
    cin >> k;

    array<int, 2> result = { Fib(k - 1),Fib(k) };
    cout << result[0] << ' ' << result[1] << '\n';
}