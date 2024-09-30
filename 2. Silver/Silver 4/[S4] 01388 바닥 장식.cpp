#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> map(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> map[i][j];
    }

    vector<vector<bool>> isVisited(n, vector<bool>(m, false));
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isVisited[i][j])
                continue;

            isVisited[i][j] = true;
            result++;

            bool dy = (map[i][j] == '|');
            bool dx = (map[i][j] == '-');

            int ny = i + dy;
            int nx = j + dx;
            while (ny < n && nx < m && map[i][j] == map[ny][nx])
            {
                isVisited[ny][nx] = true;
                ny += dy;
                nx += dx;
            }
        }
    }
    cout << result << '\n';
}