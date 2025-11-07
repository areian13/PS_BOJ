#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000u
const int t = bit_ceil(MAX + 1);

int Query(int v, int s, int e, int i, vector<int>& seg)
{
    if (s == e) return s;

    int m = (s + e) / 2;
    if (v <= seg[i * 2])
        return Query(v, s, m, i * 2, seg);
    return Query(v - seg[i * 2], m + 1, e, i * 2 + 1, seg);
}
void Update(int i, int v, vector<int>& seg)
{
    i += t;
    seg[i] += v;
    while (i > 1)
    {
        i /= 2;
        seg[i] = seg[i * 2] + seg[i * 2 + 1];
    }
}

int main()
{
    FastIO;

    vector<int> seg(t * 2, 0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int q;
        cin >> q;

        if (q == 1)
        {
            int a;
            cin >> a;

            int result = Query(a, 0, t - 1, 1, seg);
            cout << result << '\n';
            Update(result, -1, seg);
        }
        else
        {
            int a, b;
            cin >> a >> b;

            Update(a, b, seg);
        }
    }
}