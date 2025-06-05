#include <iostream>
#include <vector>
#include <bit>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

typedef vector<int> Node;

struct MGST
{
    int n, t;
    vector<Node> tree;

    MGST(vector<int>& a)
    {
        n = a.size();
        t = bit_ceil((unsigned int)n);
        tree.resize(t * 2);
        for (int i = 0; i < n; i++)
            tree[t + i].push_back(a[i]);
        for (int i = t - 1; i >= 1; i--)
            Merge(tree[i * 2], tree[i * 2 + 1], tree[i]);
    }
    static void Merge(const Node& a, const Node& b, Node& c)
    {
        c.resize(a.size() + b.size());
        merge(a.begin(), a.end(), b.begin(), b.end(), c.begin());
    }

    int Query(int i, int j, int k)
    {
        int l = i + t, r = j + t;
        int result = 0;
        while (l <= r)
        {
            if (l % 2 == 1)
            {
                result += tree[l].end() - upper_bound(tree[l].begin(), tree[l].end(), k);
                l++;
            }
            if (r % 2 == 0)
            {
                result += tree[r].end() - upper_bound(tree[r].begin(), tree[r].end(), k);
                r--;
            }
            l /= 2, r /= 2;
        }
        return result;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int m;
    cin >> m;

    MGST mgst(a);
    int p = 0;
    for (int qc = 1; qc <= m; qc++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a ^= p, b ^= p, c ^= p;
        a--, b--;

        int result = mgst.Query(a, b, c);
        cout << result << '\n';
        p = result;
    }
}