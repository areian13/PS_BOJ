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

    vector<int> cnt(n + m + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cnt[i + j]++;
    }

    int k = *max_element(cnt.begin(), cnt.end());
    for (int i = 1; i <= n + m; i++)
    {
        if (cnt[i] == k)
            cout << i << '\n';
    }
}