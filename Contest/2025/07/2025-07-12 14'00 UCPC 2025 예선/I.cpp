#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dx = { 0,1,0,-1 };
array<int, 4> dy = { 1,0,-1,0 };

struct Pos
{
    int x, y, i;
};

void BFS(Pos& s, vector<Pos>& pos,
    unordered_map<int, unordered_map<int, bool>>& map)
{
    map[s.y][s.x] = false;
    queue<Pos> Q;
    Q.push(s);

    while (!Q.empty())
    {
        auto [x, y, u] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (map.count(ny) == 0 ||
                map[ny].count(nx) == 0
                || !map[ny][nx])
                continue;

            map[ny][nx] = false;
            Q.push({ nx,ny });
        }
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Pos> pos(n);
    for (int i = 0; i < n; i++)
    {
        cin >> pos[i].y;
        pos[i].i = i;
    }

    unordered_map<int, unordered_map<int, bool>> map;
    int x = 0;
    map[pos[0].y][x] = true;
    pos[0].x = x;
    for (int i = 1; i < n; i++)
    {
        if (pos[i].y <= pos[i - 1].y)
            x++;

        map[pos[i].y][x] = true;
        pos[i].x = x;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        Pos& p = pos[i];
        if (!map[p.y][p.x])
            continue;

        BFS(p, pos, map);
        result++;
    }

    cout << result << '\n';
    cout << n << '\n';
}