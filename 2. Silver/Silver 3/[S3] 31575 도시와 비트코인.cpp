#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 2> dy = { 0,1 };
array<int, 2> dx = { 1,0 };

bool CanGo(vector<vector<char>>& map)
{
    int m = map.size();
    int n = map[0].size();

    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
    isVisited[0][0] = true;

    queue<Pos> Q;
    Q.push({ 0,0 });

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 2; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= m || nx < 0 || nx >= n)
                continue;
            if (map[ny][nx] != '1' || isVisited[ny][nx])
                continue;

            isVisited[ny][nx] = true;
            Q.push({ ny,nx });
        }
    }
    return isVisited[m - 1][n - 1];
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(m, vector<char>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    string result = (CanGo(map) ? "Yes" : "No");
    cout << result << '\n';
}