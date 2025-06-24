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
        t = bit_ceil(a.size());
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
        i += t, j += t;
        int result = 0;
        while (i <= j)
        {
            if (i % 2 == 1)
            {
                result += tree[i].end() - upper_bound(tree[i].begin(), tree[i].end(), k);
                i++;
            }
            if (j % 2 == 0)
            {
                result += tree[j].end() - upper_bound(tree[j].begin(), tree[j].end(), k);
                j--;
            }
            i /= 2, j /= 2;
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
    for (int qc = 1; qc <= m; qc++)
    {
        int i, j, k;
        cin >> i >> j >> k;
        i--, j--;

        int result = mgst.Query(i, j, k);
        cout << result << '\n';
    }
}