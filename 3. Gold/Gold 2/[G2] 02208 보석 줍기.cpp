#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> preSum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        preSum[i + 1] = preSum[i] + a;
    }

    int mSum = 0;
    int result = 0;
    for (int i = m; i <= n; i++)
    {
        mSum = min(mSum, preSum[i - m]);
        result = max(result, preSum[i] - mSum);
    }
    cout << result << '\n';
}