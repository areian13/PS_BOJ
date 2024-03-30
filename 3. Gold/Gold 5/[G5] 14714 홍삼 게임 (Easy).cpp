#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 6> dy = { 1,-1,1,-1,1,-1 };
array<int, 6> dx = { 0,0,1,-1,-1,1 };

int BFS(int n, int a, int b, int da, int db)
{
    vector<vector<int>> dist(n, vector<int>(n, -1));
    dist[a][b] = 0;

    queue<Pos> Q;
    Q.push({ a,b });

    int result = INT_MAX;
    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 6; i++)
        {
            int ny = (y + dy[i] * da + n) % n;
            int nx = (x + dx[i] * db + n) % n;

            if (ny == nx)
                result = min(result, dist[y][x] + (i >= 2) + 1);
            if (i < 2 || dist[ny][nx] != -1)
                continue;

            dist[ny][nx] = dist[y][x] + 2;
            Q.push({ ny,nx });
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, a, b, da, db;
    cin >> n >> a >> b >> da >> db;
    a--, b--;

    int dist = BFS(n, a, b, da, db);

    string result = (dist != INT_MAX ? to_string(dist) : "Evil Galazy");
    cout << result << '\n';
}