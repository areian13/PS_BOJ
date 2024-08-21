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

void BFS(Pos start, vector<vector<bool>>& isVisited, vector<vector<bool>>& cabbage)
{
    int n = cabbage.size();
    int m = cabbage[0].size();

    isVisited[start.y][start.x] = true;

    queue<Pos> Q;
    Q.push(start);

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
            if (!cabbage[ny][nx] || isVisited[ny][nx])
                continue;

            isVisited[ny][nx] = true;
            Q.push({ ny,nx });
        }
    }
}

int CountWorm(vector<vector<bool>>& cabbage)
{
    int n = cabbage.size();
    int m = cabbage[0].size();

    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!cabbage[i][j] || isVisited[i][j])
                continue;

            result++;
            BFS({ i,j }, isVisited, cabbage);
        }
    }
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        int m, n, k;
        cin >> m >> n >> k;

        vector<vector<bool>> cabbage(n, vector<bool>(m, false));
        for (int i = 0; i < k; i++)
        {
            int x, y;
            cin >> x >> y;

            cabbage[y][x] = true;
        }

        int result = CountWorm(cabbage);
        cout << result << '\n';
    }
}