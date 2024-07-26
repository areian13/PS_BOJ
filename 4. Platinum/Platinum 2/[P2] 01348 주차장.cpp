#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

struct Edge
{
    int v, w;
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

void BFS(Pos& s, vector<vector<int>>& pNode,
    vector<Edge>& edges, vector<vector<char>>& map)
{
    int r = map.size();
    int c = map[0].size();

    vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
    dist[s.y][s.x] = 0;

    queue<Pos> Q;
    Q.push(s);

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        if (map[y][x] == 'P')
            edges.push_back({ pNode[y][x],dist[y][x] });

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c)
                continue;
            if (map[ny][nx] == 'X' || dist[ny][nx] != INT_MAX)
                continue;

            dist[ny][nx] = dist[y][x] + 1;
            Q.push({ ny,nx });
        }
    }
}

bool CanMatch(int u, vector<bool>& isVisited,
    vector<int>& a, vector<int>& b,
    int k, vector<vector<Edge>>& graph)
{
    isVisited[u] = true;

    for (Edge& edge : graph[u])
    {
        int v = edge.v;
        int w = edge.w;

        if (w > k)
            continue;

        if (b[v] == -1 ||
            !isVisited[b[v]] && CanMatch(b[v], isVisited, a, b, k, graph))
        {
            a[u] = v;
            b[v] = u;
            return true;
        }
    }
    return false;
}

int MaxFlow(int n, int m, int k, vector<vector<Edge>>& graph)
{
    vector<int> a(n, -1), b(m, -1);
    int result = 0;
    for (int u = 0; u < n; u++)
    {
        if (a[u] != -1)
            continue;

        vector<bool> isVisited(n, false);
        result += CanMatch(u, isVisited, a, b, k, graph);
    }
    return result;
}

int MaxPark(vector<vector<char>>& map)
{
    int r = map.size();
    int c = map[0].size();

    vector<Pos> car;
    vector<vector<int>> pNode(r, vector<int>(c));
    int m = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == 'C')
                car.push_back({ i,j });
            if (map[i][j] == 'P')
                pNode[i][j] = m++;
        }
    }

    int n = car.size();

    if (n == 0)
        return 0;

    vector<vector<Edge>> graph(n);
    for (int i = 0; i < n; i++)
        BFS(car[i], pNode, graph[i], map);

    vector<int> k;
    for (auto& edges : graph)
    {
        for (Edge& edge : edges)
            k.push_back(edge.w);
    }
    sort(k.begin(), k.end());

    int start = 0;
    int end = k.size() - 1;
    int result = -1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        int match = MaxFlow(n, m, k[mid], graph);

        if (match < n)
            start = mid + 1;
        else
        {
            result = k[mid];
            end = mid - 1;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int r, c;
    cin >> r >> c;

    vector<vector<char>> map(r, vector<char>(c));
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cin >> map[i][j];
    }

    int result = MaxPark(map);
    cout << result << '\n';
}