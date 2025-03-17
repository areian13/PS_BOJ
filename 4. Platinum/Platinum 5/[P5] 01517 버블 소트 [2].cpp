#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long SegTree(int s, int e, int l, int r, int i, vector<long long>& tree)
{
    if (r < s || e < l)
        return 0;
    if (s <= l && r <= e)
        return tree[i];

    int m = (l + r) / 2;
    long long lSeg = SegTree(s, e, l, m, i * 2, tree);
    long long rSeg = SegTree(s, e, m + 1, r, i * 2 + 1, tree);
    return lSeg + rSeg;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    int k = bit_ceil((unsigned int)n);
    vector<long long> tree(k * 2, 0);
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = a[i].second;
        result += SegTree(idx + 1, n - 1, 0, k - 1, 1, tree);

        idx += k;
        tree[idx] = 1;

        while (idx > 1)
        {
            idx /= 2;
            tree[idx] = tree[idx * 2] + tree[idx * 2 + 1];
        }
    }

    cout << result << '\n';
}