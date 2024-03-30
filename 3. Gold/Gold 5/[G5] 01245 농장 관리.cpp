#include <iostream>
#include <vector>
#include <queue>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 8> dy = { 1,1,1,0,-1,-1,-1,0 };
array<int, 8> dx = { -1,0,1,1,1,0,-1,-1 };

struct Pos {
    int y, x;
};

int BFS(vector<vector<int>>& mount)
{
    int n = mount.size();
    int m = mount[0].size();

    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mount[i][j] == 0 || isVisited[i][j])
                continue;

            bool isPeak = true;

            isVisited[i][j] = true;

            queue<Pos> Q;
            Q.push({ i,j });

            while (!Q.empty())
            {
                int y = Q.front().y;
                int x = Q.front().x;
                Q.pop();

                for (int k = 0; k < 8; k++)
                {
                    int ny = y + dy[k];
                    int nx = x + dx[k];

                    if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                        continue;
                    if (isVisited[ny][nx] || mount[ny][nx] != mount[y][x])
                    {
                        isPeak &= (mount[ny][nx] <= mount[y][x]);
                        continue;
                    }

                    isVisited[ny][nx] = true;
                    Q.push({ ny,nx });
                }
            }
            result += isPeak;
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> mount(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mount[i][j];
    }

    int result = BFS(mount);
    cout << result << '\n';
}