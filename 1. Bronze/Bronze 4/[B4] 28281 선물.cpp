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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int cnt = INT_MAX;
    for (int i = 0; i < n - 1; i++)
        cnt = min(cnt, a[i] + a[i + 1]);

    int result = cnt * k;
    cout << result << '\n';
}