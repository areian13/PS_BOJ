#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 41

int Fib(int n)
{
    static vector<int> dp(MAX, -1);

    if (n <= 1)
        return dp[n] = n;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = Fib(n - 1) + Fib(n - 2);
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        if (n == 0)
            cout << 1 << ' ' << 0 << '\n';
        else
            cout << Fib(n - 1) << ' ' << Fib(n) << '\n';
    }
}