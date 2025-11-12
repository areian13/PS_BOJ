#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Run
{
    int i, s;
};

void Update(int i, int v, vector<int>& seg)
{
    int t = seg.size() / 2;
    i += t;
    seg[i] = v;

    while (i > 1)
    {
        i /= 2;
        seg[i] = 1LL * seg[i * 2] + seg[i * 2 + 1];
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

    vector<Run> runs(n);
    for (int i = 0; i < n; i++)
    {
        runs[i].i = i;
        cin >> runs[i].s;
    }
    sort(runs.begin(), runs.end(),
        [](const Run& a, const Run& b) { return a.s < b.s; }
    );
    for (int i = 0; i < n; i++)
        runs[i].s = i;
    sort(runs.begin(), runs.end(),
        [](const Run& a, const Run& b) { return a.i < b.i; }
    );

    int t = bit_ceil(1u * n);
    vector<int> seg(t * 2, 0);
    for (int i = 0; i < n; i++)
    {
        int result = i - Query(0, runs[i].s - 1, 0, t - 1, 1, seg) + 1;
        cout << result << '\n';
        Update(runs[i].s, 1, seg);
    }
}