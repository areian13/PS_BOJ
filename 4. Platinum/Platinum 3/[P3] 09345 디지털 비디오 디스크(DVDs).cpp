#include <iostream>
#include <bit>
#include <vector>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF INT_MAX

struct Node
{
    int m, M;

    friend Node operator + (const Node& a, const Node& b)
    {
        int m = min(a.m, b.m);
        int M = max(a.M, b.M);

        return { m,M };
    }
};

void Update(int i, const Node& v, vector<Node>& tree)
{
    int t = tree.size() / 2;

    i += t;
    tree[i] = v;

    while (i > 1)
    {
        i /= 2;
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}

Node Query(int s, int e, int l, int r, int i, vector<Node>& tree)
{
    if (r < s || e < l)
        return { INF,-INF };
    if (s <= l && r <= e)
        return tree[i];

    int m = (l + r) / 2;
    Node lSeg = Query(s, e, l, m, i * 2, tree);
    Node rSeg = Query(s, e, m + 1, r, i * 2 + 1, tree);
    return lSeg + rSeg;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, k;
        cin >> n >> k;

        int t = bit_ceil((unsigned int)n);
        vector<Node> tree(t * 2, { INF,-INF });
        for (int i = 0; i < n; i++)
            tree[t + i] = { i,i };

        for (int i = t - 1; i >= 1; i--)
            tree[i] = tree[i * 2] + tree[i * 2 + 1];

        bool isUpdated = true;
        for (int q = 1; q <= k; q++)
        {
            int query, a, b;
            cin >> query >> a >> b;

            if (query == 0)
            {
                Node aNode = tree[t + a];
                Node bNode = tree[t + b];
                Update(a, bNode, tree);
                Update(b, aNode, tree);
            }
            else
            {
                Node query = Query(a, b, 0, t - 1, 1, tree);

                bool result = (query.m == a && query.M == b);
                if (result == true)
                    cout << "YES" << '\n';
                else
                    cout << "NO" << '\n';
            }
        }
    }
}