#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

struct Pos
{
    int y, x;
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> map(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            bool tf;
            cin >> tf;

            map[i][j] = tf;
        }
    }

    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    int cnt = 0;
    int maxSize = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isVisited[i][j] || !map[i][j])
                continue;

            cnt++;
            int size = 1;

            isVisited[i][j] = true;

            queue<Pos> Q;
            Q.push({ i,j });

            while (!Q.empty())
            {
                int y = Q.front().y;
                int x = Q.front().x;
                Q.pop();

                for (int k = 0; k < 4; k++)
                {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;
                    if (isVisited[ny][nx] || !map[ny][nx])
                        continue;

                    size++;
                    isVisited[ny][nx] = true;
                    Q.push({ ny,nx });
                }
            }
            maxSize = max(maxSize, size);
        }
    }
    cout << cnt << '\n';
    cout << maxSize << '\n';
}