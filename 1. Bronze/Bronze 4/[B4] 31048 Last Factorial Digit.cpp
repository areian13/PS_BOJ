#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10

int Factoria_(int n)
{
    static array<int, MAX + 1> dp = { 0, };

    if (n <= 1)
        return dp[n] = 1;
    if (dp[n] != 0)
        return dp[n];
    return n * Factoria_(n - 1) % 10;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        int result = Factoria_(n);
        cout << result << '\n';
    }
}