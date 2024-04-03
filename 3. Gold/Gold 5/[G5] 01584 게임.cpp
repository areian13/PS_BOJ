#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <array>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define SIZE 500

struct Pos
{
    int y, x, d;

    friend bool operator<(const Pos& a, const Pos& b)
    {
        return a.d > b.d;
    }
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0 };

void SetMap(int x1, int y1, int x2, int y2, int t, vector<vector<int>>& map)
{
    if (x1 > x2)
        swap(x1, x2);
    if (y1 > y2)
        swap(y1, y2);

    for (int i = y1; i <= y2; i++)
    {
        for (int j = x1; j <= x2; j++)
            map[i][j] = t;
    }
}

int Dijkstra(vector<vector<int>>& map)
{
    vector<vector<int>> dist(SIZE + 1, vector<int>(SIZE + 1, INT_MAX));
    dist[0][0] = 0;

    priority_queue<Pos> PQ;
    PQ.push({ 0,0,0 });

    while (!PQ.empty())
    {
        int y = PQ.top().y;
        int x = PQ.top().x;
        int d = PQ.top().d;
        PQ.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny > SIZE || nx < 0 || nx > SIZE)
                continue;

            int nd = d + (map[ny][nx] == 1);
            if (map[ny][nx] == 2 || dist[ny][nx] <= nd)
                continue;

            dist[ny][nx] = nd;
            PQ.push({ ny,nx,nd });
        }
    }

    int result = (dist[SIZE][SIZE] != INT_MAX ? dist[SIZE][SIZE] : -1);
    return result;
}

int main()
{
    FastIO;

    vector<vector<int>> map(SIZE + 1, vector<int>(SIZE + 1, 0));

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        SetMap(x1, y1, x2, y2, 1, map);
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        SetMap(x1, y1, x2, y2, 2, map);
    }

    int result = Dijkstra(map);
    cout << result << '\n';
}