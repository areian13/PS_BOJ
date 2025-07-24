#include <iostream>
#include <vector>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x, z;
};

array<int, 9> dy = { -1,-1,-1,0,1,1,1,0,0 };
array<int, 9> dx = { -1,0,1,1,1,0,-1,-1,0 };

int main()
{
    FastIO;

    int n = 8;

    vector<vector<vector<char>>> map(n, vector<vector<char>>(n, vector<char>(n, '.')));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> map[i][j][0];

            if (map[i][j][0] != '#')
                continue;

            for (int k = 0; i + k < n; k++)
                map[i + k][j][k] = '#';
        }
    }

    vector<vector<vector<bool>>> isVisited(n, vector<vector<bool>>(n, vector<bool>(n, false)));
    isVisited[n - 1][0][0] = true;

    queue<Pos> Q;
    Q.push({ n - 1,0,0 });

    while (!Q.empty())
    {
        auto [y, x, z] = Q.front();
        Q.pop();

        for (int i = 0; i < 9; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            int nz = z + (z < 7);

            if (ny < 0 || ny >= n || nx < 0 || nx >= n || nz >= n)
                continue;
            if (map[ny][nx][z] == '#' || map[ny][nx][nz] == '#' || isVisited[ny][nx][nz])
                continue;

            isVisited[ny][nx][nz] = true;
            Q.push({ ny,nx,nz });
        }
    }

    bool result = isVisited[0][n - 1][n - 1];
    cout << result << '\n';
}