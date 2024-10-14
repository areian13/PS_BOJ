#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<long long> pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        long long a;
        cin >> a;

        pre[i] = pre[i - 1] + a;
    }
    sort(pre.begin() + 1, pre.end(), greater<long long>());

    long long result = 0;
    for (int i = 1; i <= k; i++)
        result += pre[i];
    cout << result << '\n';
}