#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<long long> preSum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;

        preSum[i] = preSum[i - 1] + a;
    }

    long long result = 0;
    for (int i = 1; i <= n; i++)
    {
        long long score = preSum[i] - result;
        result = max(result, score);
    }
    cout << result << '\n';
}