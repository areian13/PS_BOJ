#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> dy = { 0,1 };
array<int, 2> dx = { 1,0 };

struct Pos
{
    int y, x;
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    vector<vector<bool>> isVisited(n, vector<bool>(n, false));
    isVisited[0][0] = true;

    queue<Pos> Q;
    Q.push({ 0,0 });

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        if (map[y][x] == -1)
            break;

        for (int i = 0; i < 2; i++)
        {
            int ny = y + dy[i] * map[y][x];
            int nx = x + dx[i] * map[y][x];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            if (isVisited[ny][nx])
                continue;

            isVisited[ny][nx] = true;
            Q.push({ ny,nx });
        }
    }

    string result = (isVisited[n - 1][n - 1] ? "HaruHaru" : "Hing");
    cout << result << '\n';
}