#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c;
};

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

void BFS(Pos s, int k, vector<vector<int>>& area,
    vector<vector<char>>& map)
{
    int n = map.size();
    int m = map[0].size();

    queue<Pos> Q;
    Q.push(s);
    area[s.r][s.c] = k;

    while (!Q.empty())
    {
        auto [r, c] = Q.front();
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            if (map[nr][nc] == '.' || area[nr][nc] != -1)
                continue;

            area[nr][nc] = k;
            Q.push({ nr,nc });
        }
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    bool isManhattan = false;
    while (!isManhattan)
    {
        vector<vector<int>> area(n, vector<int>(m, -1));
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == '.' || area[i][j] != -1)
                    continue;

                BFS({ i,j }, k++, area, map);
            }
        }

        isManhattan = true;
        for (int i = 0; i < n; i++)
        {
            vector<pair<int, int>> col(k, { m,-1 });
            for (int j = 0; j < m; j++)
            {
                if (area[i][j] == -1)
                    continue;

                auto& c = col[area[i][j]];
                c.first = c.first == m ? j : c.first;
                c.second = j;
            }
            for (auto& c : col)
            {
                for (int j = c.first; j <= c.second; j++)
                {
                    isManhattan &= (map[i][j] == '#');
                    map[i][j] = '#';
                }
            }
        }

        for (int j = 0; j < m; j++)
        {
            vector<pair<int, int>> row(k, { n,-1 });
            for (int i = 0; i < n; i++)
            {
                if (area[i][j] == -1)
                    continue;

                auto& r = row[area[i][j]];
                r.first = r.first == n ? i : r.first;
                r.second = i;
            }
            for (auto& r : row)
            {
                for (int i = r.first; i <= r.second; i++)
                {
                    isManhattan &= (map[i][j] == '#');
                    map[i][j] = '#';
                }
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << map[i][j];
        cout << '\n';
    }
}