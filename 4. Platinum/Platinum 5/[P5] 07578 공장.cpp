#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000'000;

void Update(int i, int v, vector<int>& seg)
{
    int t = seg.size() / 2;
    i += t;
    seg[i] = v;

    while (i > 1)
    {
        i /= 2;
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}
int Query(int s, int e, int l, int r, int i, vector<int>& seg)
{
    if (r < s || e < l) return 0;
    if (s <= l && r <= e) return seg[i];

    int m = (l + r) / 2;
    int lq = Query(s, e, l, m, i * 2, seg);
    int rq = Query(s, e, m + 1, r, i * 2 + 1, seg);
    return lq + rq;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> idx(MAX + 1);
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        idx[a] = i;
    }

    int t = bit_ceil(1u * n);
    vector<int> seg(t * 2, 0);
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        int b;
        cin >> b;

        result += Query(idx[b], n - 1, 0, t - 1, 1, seg);
        Update(idx[b], 1, seg);
    }
    cout << result << '\n';
}