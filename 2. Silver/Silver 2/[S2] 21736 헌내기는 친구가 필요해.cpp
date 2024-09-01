#include <iostream>
#include <vector>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    Pos s = { -1,-1 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            if (map[i][j] == 'I')
                s = { i,j };
        }
    }

    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    isVisited[s.y][s.x] = true;

    queue<Pos> Q;
    Q.push(s);

    int result = 0;
    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (isVisited[ny][nx] || map[ny][nx] == 'X')
                continue;

            result += (map[ny][nx] == 'P');
            isVisited[ny][nx] = true;
            Q.push({ ny,nx });
        }
    }

    if (result > 0)
        cout << result << '\n';
    else
        cout << "TT" << '\n';
}