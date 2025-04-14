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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int l = 0, r = 0;
    int cnt = 0;
    int result = n + 1;
    while (r < n)
    {
        if (a[r] == 1)
            cnt++;

        while (cnt == k)
        {
            result = min(result, r - l + 1);
            cnt -= (a[l] == 1);
            l++;
        }
        r++;
    }

    if (result == n + 1)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}