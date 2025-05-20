#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10

int Count123Sum(int n)
{
    static vector<int> dp(MAX + 1, -1);
    static bool isInited = false;

    if (!isInited)
    {
        isInited = true;
        dp[0] = 1;
    }

    if (n < 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = Count123Sum(n - 1) + Count123Sum(n - 2) + Count123Sum(n - 3);
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

        int result = Count123Sum(n);
        cout << result << '\n';
    }
}