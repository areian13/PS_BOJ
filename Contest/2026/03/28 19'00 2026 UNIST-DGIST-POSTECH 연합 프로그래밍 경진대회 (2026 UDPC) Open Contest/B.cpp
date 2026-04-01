#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

pair<int, int> SwapLIS(vector<int>& a)
{
    int n = a.size();

    int l = -1, r = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != i + 1)
        {
            l = i;
            break;
        }
    }
    if (l == -1) return { -1,-1 };

    for (int j = l + 1; j < n; j++)
    {
        if (a[j] == l + 1)
            return { l,j };
    }
    return { -1,-1 };
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    auto [l, r] = SwapLIS(a);
    if (l == -1) cout << "NO" << '\n';
    else cout << "YES" << '\n' << l + 1 << ' ' << r + 1 << '\n';
}