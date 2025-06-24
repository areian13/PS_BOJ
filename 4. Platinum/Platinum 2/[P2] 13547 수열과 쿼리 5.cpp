#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Query
{
    int i, s, e;
};

int main()
{
    FastIO;

    int n, sn;
    cin >> n;
    sn = sqrt(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    vector<Query> qs(m);
    for (int i = 0; i < m; i++)
    {
        int s, e;
        cin >> s >> e;
        s--, e--;

        qs[i] = { i,s,e };
    }
    sort(qs.begin(), qs.end(),
        [&sn](Query& a, Query& b)
        {
            if (a.s / sn != b.s / sn)
                return a.s < b.s;
            return a.e < b.e;
        }
    );

    int s = qs[0].s, e = qs[0].e;
    vector<int> cnt(1'000'001, 0);
    int v = 0;
    for (int i = s; i <= e; i++)
        v += (cnt[a[i]]++ == 0);

    vector<int> result(m);
    result[qs[0].i] = v;
    for (int i = 1; i < m; i++)
    {
        while (s < qs[i].s)
            v -= (--cnt[a[s++]] == 0);
        while (s > qs[i].s)
            v += (cnt[a[--s]]++ == 0);
        while (e < qs[i].e)
            v += (cnt[a[++e]]++ == 0);
        while (e > qs[i].e)
            v -= (--cnt[a[e--]] == 0);

        result[qs[i].i] = v;
    }

    for (int i = 0; i < m; i++)
        cout << result[i] << '\n';
}