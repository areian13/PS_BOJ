#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;
};

struct Edge
{
    int u, v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w < b.w;
    }
};

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[v] = u;
}

int MinRoadCost(int n, vector<Edge>& edges, vector<vector<Edge>>& tree)
{
    sort(edges.begin(), edges.end());

    vector<int> p(n, -1);
    int result = 0;
    for (Edge& edge : edges)
    {
        int u = Find(edge.u, p);
        int v = Find(edge.v, p);

        if (u == v)
            continue;

        Union(u, v, p);
        result += edge.w;

        tree[edge.u].push_back({ edge.u,edge.v,edge.w });
        tree[edge.v].push_back({ edge.v,edge.u,edge.w });
    }
    return result;
}

void DFS(Edge cur, Edge& farNode, vector<bool>& isVisited, vector<vector<Edge>>& tree)
{
    isVisited[cur.v] = true;

    if (farNode.w < cur.w)
        farNode = cur;

    for (Edge& nxt : tree[cur.v])
    {
        if (isVisited[nxt.v])
            continue;

        DFS({ -1,nxt.v, cur.w + nxt.w }, farNode, isVisited, tree);
    }
}

int TreeDiameter(vector<vector<Edge>>& tree)
{
    int n = tree.size();
    vector<bool> isVisited(n, false);

    Edge farNode = { -1,-1,0 };
    DFS({ -1,0,0 }, farNode, isVisited, tree);


    Edge result = { -1,-1,0 };
    fill(isVisited.begin(), isVisited.end(), false);
    DFS({ -1,farNode.v,0 }, result, isVisited, tree);

    return result.w;
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<Edge> edges(k);
    for (int i = 0; i < k; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        edges[i] = { u,v,w };
    }

    array<int, 2> result;
    vector<vector<Edge>> tree(n);
    result[0] = MinRoadCost(n, edges, tree);
    result[1] = TreeDiameter(tree);

    cout << result[0] << '\n';
    cout << result[1] << '\n';
}