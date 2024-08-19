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

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> board(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> board[i][j];
    }

    vector<vector<bool>> isVisited(n, vector<bool>(n, false));
    int spore = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == 1 || isVisited[i][j])
                continue;

            int size = 1;

            isVisited[i][j] = true;

            queue<Pos> Q;
            Q.push({ i,j });

            while (!Q.empty())
            {
                int y = Q.front().y;
                int x = Q.front().x;
                Q.pop();

                for (int i = 0; i < 4; i++)
                {
                    int ny = y + dy[i];
                    int nx = x + dx[i];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                        continue;
                    if (board[ny][nx] == 1 || isVisited[ny][nx])
                        continue;

                    size++;
                    isVisited[ny][nx] = true;
                    Q.push({ ny,nx });
                }
            }
            spore += size / k + (size % k != 0);
        }
    }
    if (1 <= spore && spore <= m)
    {
        cout << "POSSIBLE" << '\n';
        cout << m - spore << '\n';

    }
    else
        cout << "IMPOSSIBLE" << '\n';
}