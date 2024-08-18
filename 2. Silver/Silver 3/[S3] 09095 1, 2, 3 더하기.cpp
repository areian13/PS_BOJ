#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 11

int Count123Sum(int n)
{
    static vector<int> dp(MAX + 1, -1);
    if (dp[n] != -1)
        return dp[n];
    if (n <= 3)
        return dp[n] = (n == 3 ? 4 : n);
    return dp[n] = Count123Sum(n - 1) + Count123Sum(n - 2) + Count123Sum(n - 3);
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

        int result = Count123Sum(n);
        cout << result << '\n';
    }
}