#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

struct Pos
{
    int r, c;
};

bool CanLight(vector<Pos>& s, vector<Pos>& e, vector<vector<int>>& map)
{
    int h = map.size();
    int w = map[0].size();

    vector<vector<int>> dist(h, vector<int>(w, 0));
    queue<Pos> Q;
    for (Pos& p : s)
    {
        dist[p.r][p.c] = 16;
        Q.push(p);
    }

    while (!Q.empty())
    {
        int r = Q.front().r;
        int c = Q.front().c;
        Q.pop();

        if (map[r][c] == 1 || dist[r][c] == 0)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= h || nc < 0 || nc >= w)
                continue;
            if (map[nr][nc] == -1 || dist[nr][nc] >= dist[r][c] - 1)
                continue;

            dist[nr][nc] = dist[r][c] - 1;
            Q.push({ nr,nc });
        }
    }

    for (Pos& p : e)
    {
        if (dist[p.r][p.c] == 0)
            return false;
    }
    return true;
}

int main()
{
    FastIO;

    int w, h, n;
    cin >> w >> h >> n;

    vector<Pos> s, e;
    vector<vector<int>> map(h, vector<int>(w, -1));
    for (int i = 0; i < n; i++)
    {
        string b;
        int x, y;
        cin >> b >> x >> y;

        if (b == "redstone_block")
        {
            s.push_back({ y,x });
            map[y][x] = 0;
        }
        else if (b == "redstone_lamp")
        {
            e.push_back({ y,x });
            map[y][x] = 1;
        }
        else
            map[y][x] = 2;
    }

    bool result = CanLight(s, e, map);
    if (result == true)
        cout << "success" << '\n';
    else
        cout << "failed" << '\n';
}