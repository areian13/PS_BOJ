#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Maal
{
    bool can;
    int cnt;
};

struct Pos
{
    int y, x;
    int d;
};

array<int, 8> dy = { 2,1,-1,-2,-2,-1,1,2 };
array<int, 8> dx = { 1,2,2,1,-1,-2,-2,-1 };

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<Maal>> distSum(n, vector<Maal>(m, { true,0 }));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char maal;
            cin >> maal;

            if (maal == '.')
                continue;

            int k = maal - '0';
            vector<vector<int>> dist(n, vector<int>(m, -1));
            dist[i][j] = 0;

            queue<Pos> Q;
            Q.push({ i,j,0 });

            while (!Q.empty())
            {
                auto [y, x, d] = Q.front();
                Q.pop();

                for (int t = 0; t < 8; t++)
                {
                    int ny = y + dy[t];
                    int nx = x + dx[t];
                    int nd = (d - 1 + k) % k;

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;
                    if (dist[ny][nx] != -1)
                        continue;

                    dist[ny][nx] = dist[y][x] + (d == 0);
                    Q.push({ ny,nx,nd });
                }
            }

            for (int t = 0; t < n; t++)
            {
                for (int l = 0; l < m; l++)
                {
                    distSum[t][l].can &= (dist[t][l] != -1);
                    distSum[t][l].cnt += dist[t][l];
                }
            }
        }
    }

    int result = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (distSum[i][j].can)
                result = min(result, distSum[i][j].cnt);
        }
    }

    if (result == INT_MAX)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}