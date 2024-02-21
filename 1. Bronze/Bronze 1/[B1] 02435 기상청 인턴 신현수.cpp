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

    vector<int> t(n);
    for (int i = 0; i < n; i++)
        cin >> t[i];

    int sum = 0;
    for (int i = 0; i < k; i++)
        sum += t[i];

    int result = sum;
    for (int i = k; i < n; i++)
    {
        sum += t[i] - t[i - k];
        result = max(result, sum);
    }
    cout << result << '\n';
}