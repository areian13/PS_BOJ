#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x, i;
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { 1,0,-1,0 };

void BFS(Pos& s, vector<bool>& isVisited, vector<Pos>& pos,
    unordered_map<int, unordered_map<int, int>>& map)
{
    isVisited[s.i] = true;
    queue<Pos> Q;
    Q.push(s);

    while (!Q.empty())
    {
        auto [y, x, u] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (map.count(ny) == 0 ||
                map[ny].count(nx) == 0 ||
                isVisited[map[ny][nx]])
                continue;

            isVisited[map[ny][nx]] = true;
            Q.push({ ny,nx });
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

    unordered_map<int, unordered_map<int, int>> map;
    int x = 0;
    pos[0].x = x;
    map[pos[0].y][x] = pos[0].i;
    for (int i = 1; i < n; i++)
    {
        if (pos[i].y <= pos[i - 1].y)
            x++;

        pos[i].x = x;
        map[pos[i].y][x] = pos[i].i;
    }

    vector<bool> isVisited(n, false);
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (isVisited[i])
            continue;

        result++;
        BFS(pos[i], isVisited, pos, map);
    }

    cout << result << '\n';
    cout << n << '\n';
}