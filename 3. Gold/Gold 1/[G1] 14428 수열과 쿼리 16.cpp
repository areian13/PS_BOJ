#include <iostream>
#include <bit>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    int v, i;

    friend bool operator<(const Node& a, const Node& b)
    {
        if (a.v != b.v)
            return a.v < b.v;
        return a.i < b.i;
    }
};

Node SegTree(int start, int end, int idx, int l, int r, vector<Node>& a)
{
    if (r < start || end < l)
        return { INT_MAX,INT_MAX };
    if (start <= l && r <= end)
        return a[idx];

    int mid = (l + r) / 2;
    return min(SegTree(start, end, idx * 2, l, mid, a),
        SegTree(start, end, idx * 2 + 1, mid + 1, r, a));
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int t = bit_ceil((unsigned int)n);
    vector<Node> a(t * 2, { INT_MAX,INT_MAX });
    for (int i = 0; i < n; i++)
    {
        int v;
        cin >> v;

        a[t + i] = { v,i };
    }
    for (int i = t - 1; i > 0; i--)
        a[i] = min(a[i * 2], a[i * 2 + 1]);

    int m;
    cin >> m;

    while (m--)
    {
        int c, i, j;
        cin >> c >> i >> j;

        if (c == 1)
        {
            i += t - 1;
            a[i].v = j;
            while (i > 1)
            {
                i /= 2;
                a[i] = min(a[i * 2], a[i * 2 + 1]);
            }
        }
        else
        {
            i--, j--;
            Node result = SegTree(i, j, 1, 0, t - 1, a);
            cout << result.i + 1 << '\n';
        }
    }
}