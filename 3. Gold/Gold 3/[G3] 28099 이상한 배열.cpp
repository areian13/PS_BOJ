#include <iostream>
#include <bit>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int SegTree(int start, int end, int idx, int l, int r, vector<int>& a)
{
    if (end < l || r < start)
        return 0;
    if (start <= l && r <= end)
        return a[idx];

    int mid = (l + r) / 2;
    return max(SegTree(start, end, idx * 2, l, mid, a),
        SegTree(start, end, idx * 2 + 1, mid + 1, r, a));
}

bool IsStrange(int n, vector<int>& a, vector<array<int, 2>>& nIdx)
{
    int size = a.size() / 2;

    for (int i = size - 1; i > 0; i--)
        a[i] = max(a[i * 2], a[i * 2 + 1]);

    for (int i = 1; i <= n; i++)
    {
        if (nIdx[i][0] == nIdx[i][1])
            continue;

        if (i < SegTree(nIdx[i][0], nIdx[i][1], 1, 0, size - 1, a))
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int n;
        cin >> n;

        int t = bit_ceil((unsigned int)n);

        vector<int> a(2 * t, 0);
        vector<array<int, 2>> nIdx(n + 1, { -1,-1 });
        for (int i = 0; i < n; i++)
        {
            cin >> a[t + i];

            if (nIdx[a[t + i]][0] == -1)
                nIdx[a[t + i]][0] = i;
            nIdx[a[t + i]][1] = i;
        }

        bool result = IsStrange(n, a, nIdx);
        if (result)
            cout << "Yes" << '\n';
        else
            cout << "No" << '\n';
    }
}