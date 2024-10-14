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

    vector<int> diff(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        diff[i] = b - a;
    }
    sort(diff.begin(), diff.end());

    int result = max(diff[k - 1], 0);
    cout << result << '\n';
}