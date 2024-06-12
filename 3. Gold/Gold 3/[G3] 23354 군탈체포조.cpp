#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x, i;

    friend bool operator<(const Pos& a, const Pos& b)
    {
        return a.i < b.i;
    }
};

struct Edge
{
    Pos v;
    int w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

void Dijkstra(Pos s, vector<vector<int>>& dist, vector<vector<int>>& map)
{
    int n = map.size();

    dist[s.y][s.x] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ { s },0 });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int w = PQ.top().w;
        PQ.pop();

        if (dist[y][x] < w)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            int nw = w + max(map[ny][nx], 0);
            if (dist[ny][nx] <= nw)
                continue;

            dist[ny][nx] = nw;
            PQ.push({ { ny,nx },nw });
        }
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    vector<Pos> seq;
    Pos s;
    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j];

            if (map[i][j] == -1)
                s = { i,j,k++ };
            if (map[i][j] == 0)
                seq.push_back({ i,j,k++ });
        }
    }
    seq.insert(seq.begin(), s);
    seq.push_back(s);

    vector<vector<vector<int>>> dists(k, vector<vector<int>>(n, vector<int>(n, INT_MAX)));
    for (int i = 0; i < k; i++)
        Dijkstra(seq[i], dists[seq[i].i], map);

    int result = INT_MAX;
    do
    {
        int dist = 0;
        for (int i = 0; i < k; i++)
            dist += dists[seq[i].i][seq[i + 1].y][seq[i + 1].x];

        result = min(result, dist);
    } while (next_permutation(seq.begin() + 1, seq.end() - 1));

    cout << result << '\n';
}