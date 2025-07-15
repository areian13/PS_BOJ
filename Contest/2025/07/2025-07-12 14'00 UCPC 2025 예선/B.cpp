#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

array<int, 4> dr = { 0,1,0,-1 };
array<int, 4> dc = { 1,0,-1,0 };

struct Pos
{
    int r, c;
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(m));
    int minV = INF;
    Pos s = { -1,-1 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];

            if (map[i][j] < minV)
            {
                minV = map[i][j];
                s = { i,j };
            }
        }
    }

    long long result = minV;
    map[s.r][s.c] = 0;
    for (int i = 0; i < 4; i++)
    {
        int nr = s.r + dr[i];
        int nc = s.c + dc[i];

        if (nr < 0 || nr >= n || nc < 0 || nc >= m)
            continue;

        map[nr][nc] -= minV;
        break;
    }

    queue<Pos> Q;
    Q.push(s);
    vector<vector<bool>> visit(n,vector<bool>(m, false));
    visit[s.r][s.c] = true;
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
            if (visit[nr][nc])
                continue;

            result += map[nr][nc];
            visit[nr][nc] = true;
            Q.push({ nr,nc });
        }
    }
    cout << result << '\n';
}