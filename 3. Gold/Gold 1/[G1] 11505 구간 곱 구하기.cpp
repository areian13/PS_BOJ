#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MOD = 1'000'000'007;

void Update(int i, int v, vector<int>& seg)
{
    int t = seg.size() / 2;
    i += t;
    seg[i] = v;

    while (i > 1)
    {
        i /= 2;
        seg[i] = 1LL * seg[i * 2] * seg[i * 2 + 1] % MOD;
    }
}
int Query(int s, int e, int l, int r, int i, vector<int>& seg)
{
    if (r < s || e < l) return 1;
    if (s <= l && r <= e) return seg[i];

    int m = (l + r) / 2;
    int lq = Query(s, e, l, m, i * 2, seg);
    int rq = Query(s, e, m + 1, r, i * 2 + 1, seg);
    return 1LL * lq * rq % MOD;
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    int t = bit_ceil(1ul * n);
    vector<int> seg(t * 2, 1);
    for (int i = 0; i < n; i++)
        cin >> seg[t + i];
    for (int i = t - 1; i >= 1; i--)
        seg[i] = 1LL * seg[i * 2] * seg[i * 2 + 1] % MOD;

    int QC = m + k;
    for (int qc = 1; qc <= QC; qc++)
    {
        int q, a, b;
        cin >> q >> a >> b;

        if (q == 1)
            Update(a - 1, b, seg);
        else
        {
            a--, b--;
            int result = Query(a, b, 0, t - 1, 1, seg);
            cout << result << '\n';
        }
    }
}