#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

namespace std
{
    template <>
    struct hash<vector<int>>
    {
        size_t operator()(const vector<int>& v) const
        {
            size_t seed = 0;
            for (int x : v)
                seed ^= hash<int>{}(x)+0x9e3779b9 + (seed << 6) + (seed >> 2);
            return seed;
        }
    };
}

struct Control
{
    int l, r, c;
};
struct Edge
{
    vector<int> v;
    int w;
};

bool IsInc(vector<int>& a)
{
    int p = INT_MIN;
    for (int x : a)
    {
        if (x < p)
            return false;
        p = x;
    }
    return true;
}
int MinControl(vector<int>& a, vector<Control>& controls)
{
    unordered_map<vector<int>, int> dist;
    dist[a] = 0;

    auto comp = [](const Edge& a, const Edge& b) { return a.w > b.w; };
    priority_queue<Edge, vector<Edge>, decltype(comp)> PQ(comp);
    PQ.push({ a,0 });

    while (!PQ.empty())
    {
        auto [u, w] = PQ.top();
        PQ.pop();

        if (IsInc(u))
            return w;

        for (auto& [l, r, c] : controls)
        {
            vector<int> v = u;
            swap(v[l], v[r]);
            int nw = w + c;

            if (dist.count(v) == 1 && dist[v] <= nw)
                continue;

            dist[v] = nw;
            PQ.push({ v,nw });
        }
    }
    return -1;
}

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

    vector<Control> controls(m);
    for (Control& control : controls)
    {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;

        control = { u,v,w };
    }

    int result = MinControl(a, controls);
    cout << result << '\n';
}