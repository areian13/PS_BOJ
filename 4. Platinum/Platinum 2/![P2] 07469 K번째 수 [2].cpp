#include <iostream>
#include <vector>
#include <algorithm>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Value
{
    int v, i, c;
};
struct Node
{
    int v;
    int l, r;
};
struct PST
{
    int n;
    vector<Node> nodes;
    vector<int> roots;

    PST(int n, int m) : n(n)
    {
        nodes.reserve(n + m * bit_width((unsigned int)n - 1));
        roots.push_back(Build(0, n - 1));
    }
    int Build(int s, int e)
    {
        int u = nodes.size();
        nodes.push_back(Node());

        if (s == e)
        {
            nodes[u].v = 0;
            return u;
        }

        int m = (s + e) / 2;
        nodes[u].l = Build(s, m);
        nodes[u].r = Build(m + 1, e);
        return u;
    }

    int Update(int x, int y)
    {
        int p = roots.back();
        if(roots.size())
        roots.push_back(Update(p, 0, n-1, )
    }
    int Update(int p, int s, int e, int y)
    {

    }
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<Value> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].v;
        a[i].i = i;
    }
    sort(a.begin(), a.end(),
        [](const auto& a, const auto& b)
        {
            return a.v < b.v;
        }
    );
    for (int i = 0; i < n; i++)
        a[i].c = i;
    sort(a.begin(), a.end(),
        [](const auto& a, const auto& b)
        {
            return a.i < b.i;
        }
    );


}