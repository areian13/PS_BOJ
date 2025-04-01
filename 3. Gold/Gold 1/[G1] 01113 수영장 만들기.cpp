#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int WaterInPool(vector<vector<int>>& pool)
{
    int n = pool.size();
    int m = pool[0].size();

    int result = 0;
    for (int h = 1; h <= 9; h++)
    {
        vector<vector<bool>> isVisited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (isVisited[i][j] || pool[i][j] >= h)
                    continue;

                isVisited[i][j] = true;

                queue<Pos> Q;
                Q.push({ i,j });

                int cnt = 1;
                bool canInWater = true;

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
                        {
                            canInWater = false;
                            continue;
                        }
                        if (pool[ny][nx] >= h || isVisited[ny][nx])
                            continue;

                        cnt++;
                        isVisited[ny][nx] = true;
                        Q.push({ ny,nx });
                    }
                }
                result += cnt * canInWater;
            }
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> pool(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char h;
            cin >> h;

            pool[i][j] = (h - '0');
        }
    }

    int result = WaterInPool(pool);
    cout << result << '\n';
}