#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> preSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int t;
        cin >> t;

        preSum[i] = preSum[i - 1] + t;
    }

    int result = INT_MIN;
    for (int i = k; i <= n; i++)
        result = max(result, preSum[i] - preSum[i - k]);
    cout << result << '\n';
}