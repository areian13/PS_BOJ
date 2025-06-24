#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Node
{
    int i, a, h, l = -1, r = -1;
};

bool MakeTree(vector<Node>& nodes)
{
    sort(nodes.begin(), nodes.end(),
        [](auto& a, auto& b)
        {
            if (a.h != b.h)
                return a.h < b.h;
            return a.a < b.a;
        }
    );

    int n = nodes.size();
    int h = nodes.back().h + 1;

    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (nodes[i].h > j)
            return false;
        j += (nodes[i].h == j);
    }

    vector<vector<Node>> tree(h);
    for (int i = 0; i < n; i++)
        tree[nodes[i].h].push_back(nodes[i]);
    if (tree[0].size() != 1)
        return false;
    for (int i = 0; i < h - 1; i++)
    {
        if (tree[i].size() * 2 < tree[i + 1].size())
            return false;

        int m = tree[i].size();
        for (int j = 0; j < m; j++)
        {

        }
    }


    return true;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Node> nodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].a >> nodes[i].h;
        nodes[i].h--;
        nodes[i].i = i;
    }

    if (MakeTree(nodes))
    {
        for (auto& node : nodes)
            cout << node.l << ' ' << node.r << '\n';
    }
    else
        cout << -1 << '\n';
}