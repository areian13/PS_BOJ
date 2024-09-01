#include <iostream>
#include <vector>
#include <unordered_map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 100'000

int A(int i)
{
    static vector<int> dp(MAX + 1, -1);
    static unordered_map<int, bool> isExisted;
    static bool isInited = false;

    if (!isInited)
    {
        dp[0] = 0;
        isExisted[0] = true;
        isInited = true;
    }

    if (dp[i] != -1)
        return dp[i];

    dp[i] = A(i - 1) - i;
    if (dp[i] < 0 || isExisted[dp[i]])
        dp[i] = A(i - 1) + i;
    isExisted[dp[i]] = true;

    return dp[i];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = A(n);
    cout << result << '\n';
}