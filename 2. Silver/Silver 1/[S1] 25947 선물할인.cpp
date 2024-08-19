#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CountBuyableItem(int b, int a, vector<int>& item)
{
    int n = item.size();

    vector<long long> preSum(n + 1, 0);
    for (int i = 0; i < n; i++)
        preSum[i + 1] = preSum[i] + item[i];

    for (int i = 1; i <= n; i++)
    {
        long long sum = (i >= a ? preSum[i - a] + (preSum[i] - preSum[i - a]) / 2 : preSum[i] / 2);
        if (sum > b)
            return i - 1;
    }
    return n;
}

int main()
{
    FastIO;

    int n, b, a;
    cin >> n >> b >> a;

    vector<int> item(n);
    for (int i = 0; i < n; i++)
        cin >> item[i];
    sort(item.begin(), item.end());

    int result = CountBuyableItem(b, a, item);
    cout << result << '\n';
}