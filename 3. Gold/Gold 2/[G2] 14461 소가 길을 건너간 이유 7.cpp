#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define CNT 3

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

struct Pos
{
    int y, x;
};

struct Edge
{
    Pos v;
    int k;
    long long w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

long long MinTime(int t, vector<vector<int>>& map)
{
    int n = map.size();

    vector<vector<vector<long long>>> dist(CNT, vector<vector<long long>>(n, vector<long long>(n, INT_MAX)));
    dist[0][0][0] = 0;

    priority_queue<Edge> PQ;
    PQ.push({ 0,0,0,0 });

    while (!PQ.empty())
    {
        int y = PQ.top().v.y;
        int x = PQ.top().v.x;
        int k = PQ.top().k;
        long long w = PQ.top().w;
        PQ.pop();

        if (dist[k][y][x] < w)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            int nk = (k + 1) % CNT;
            long long nw = w + map[ny][nx] * (nk == 0) + t;
            if (dist[nk][ny][nx] <= nw)
                continue;

            dist[nk][ny][nx] = nw;
            PQ.push({ ny,nx,nk,nw });
        }
    }

    long long result = LLONG_MAX;
    for (int i = 0; i < CNT; i++)
        result = min(result, dist[i][n - 1][n - 1]);
    return result;
}

int main()
{
    FastIO;

    int n, t;
    cin >> n >> t;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    long long result = MinTime(t, map);
    cout << result << '\n';
}