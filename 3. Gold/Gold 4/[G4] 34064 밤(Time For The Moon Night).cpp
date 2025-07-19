#include <iostream>
#include <vector>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c;
};

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

void BFS(int sr, int sc, int k,
    vector<vector<int>>& mark, vector<vector<bool>>& map)
{
    int n = map.size();
    int m = map[0].size();

    queue<Pos> Q;
    Q.push({ sr,sc });
    mark[sr][sc] = k;

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
            if (map[nr][nc] || mark[nr][nc] != -1)
                continue;

            mark[nr][nc] = k;
            Q.push({ nr,nc });
        }
    }
}

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> map(n, vector<bool>(m, false));
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        x--, y--;

        map[x][y] = true;
    }

    vector<vector<int>> a(2, vector<int>(4));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> a[i][j];
            a[i][j]--;
        }
    }

    vector<vector<int>> mark(n, vector<int>(m, -1));
    int area = 0;
    for (int i = a[0][0]; i <= a[0][2]; i++)
    {
        for (int j = a[0][1]; j <= a[0][3]; j++)
        {
            if (map[i][j] || mark[i][j] != -1)
                continue;

            BFS(i, j, area++, mark, map);
        }
    }
    vector<vector<int>> cnt(area, vector<int>(2, 0));
    for (int k = 0; k < 2; k++)
    {
        for (int i = a[k][0]; i <= a[k][2]; i++)
        {
            for (int j = a[k][1]; j <= a[k][3]; j++)
            {
                if (mark[i][j] != -1)
                    cnt[mark[i][j]][k] += !map[i][j];
            }
        }
    }

    long long result = 0;
    for (int i = 0; i < area; i++)
        result += 1LL * cnt[i][0] * cnt[i][1];
    cout << result << '\n';
}