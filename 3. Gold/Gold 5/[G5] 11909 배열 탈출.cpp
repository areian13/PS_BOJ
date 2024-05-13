#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x, d;

    friend bool operator<(const Pos& a, const Pos& b)
    {
        return a.d > b.d;
    }
};

array<int, 2> dy = { 0,1 };
array<int, 2> dx = { 1,0 };

int MinEscapeCost(vector<vector<int>>& map)
{
    int n = map.size();

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = 0;

    priority_queue<Pos> PQ;
    PQ.push({ 0,0,0 });

    while (!PQ.empty())
    {
        int y = PQ.top().y;
        int x = PQ.top().x;
        int d = PQ.top().d;
        PQ.pop();

        for (int i = 0; i < 2; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny >= n || nx >= n)
                continue;

            int nd = d + max(map[ny][nx] - map[y][x] + 1, 0);
            if (dist[ny][nx] <= nd)
                continue;

            dist[ny][nx] = nd;
            PQ.push({ ny,nx,nd });
        }
    }
    return dist[n - 1][n - 1];
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    int result = MinEscapeCost(map);
    cout << result << '\n';
}