#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 3'000'000;

void Update(int i, int v, vector<int>& seg)
{
    int t = seg.size() / 2;
    i += t;
    seg[i] += v;

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

    vector<vector<int>> h(4, vector<int>(n, 0));
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> h[i][j];
    }

    vector<int> s(MAX + 1, 0);
    for (int j = 0; j < n; j++)
    {
        int k = 0;
        for (int i = 1; i <= 3; i++)
        {
            h[i][j] += h[i - 1][j];

            while (k < h[i][j])
                s[k++] += (i == 3 ? 5 : i);
        }
    }

    int QC;
    cin >> QC;

    constexpr int t = bit_ceil(1u * MAX);
    vector<int> seg(t * 2, 0);
    for (int qc = 1; qc <= QC; qc++)
    {
        int q;
        cin >> q;
        q--;

        int result = s[q + Query(0, q, 0, t - 1, 1, seg)];
        cout << result << '\n';
        Update(q, 1, seg);
    }
}