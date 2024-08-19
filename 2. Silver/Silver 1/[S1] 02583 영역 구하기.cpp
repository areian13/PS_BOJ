#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int DFS(int y, int x, vector<vector<bool>>& isVisited, vector<vector<int>>& map)
{
    int m = map.size();
    int n = map[0].size();

    isVisited[y][x] = true;
    int area = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n)
            continue;
        if (map[ny][nx] == 1 || isVisited[ny][nx])
            continue;

        area += DFS(ny, nx, isVisited, map);
    }
    return area;
}

int main()
{
    FastIO;

    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<int>> map(m, vector<int>(n, false));
    for (int i = 0; i < k; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int i = m - y1 - 1; i >= m - y2; i--)
        {
            for (int j = x1; j < x2; j++)
                map[i][j] = 1;
        }
    }

    vector<int> result;
    vector<vector<bool>> isVisited(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == 1 || isVisited[i][j])
                continue;

            int area = DFS(i, j, isVisited, map);
            result.push_back(area);
        }
    }
    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (int area : result)
        cout << area << ' ';
    cout << '\n';
}