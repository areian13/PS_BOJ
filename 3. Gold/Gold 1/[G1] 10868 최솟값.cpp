#include <iostream>
#include <bit>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int Query(int s, int e, int l, int r, int i, vector<int>& seg)
{
    if (r < s || e < l)
        return INF;
    if (s <= l && r <= e)
        return seg[i];

    int m = (l + r) / 2;
    int lq = Query(s, e, l, m, i * 2, seg);
    int rq = Query(s, e, m + 1, r, i * 2 + 1, seg);
    return min(lq, rq);
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    int t = bit_ceil(1u * n);
    vector<int> seg(t * 2, INF);
    for (int i = 0; i < n; i++)
        cin >> seg[t + i];
    for (int i = t - 1; i > 0; i--)
        seg[i] = min(seg[i * 2], seg[i * 2 + 1]);

    for (int qc = 1; qc <= m; qc++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        int result = Query(a, b, 0, t - 1, 1, seg);
        cout << result << '\n';
    }
}