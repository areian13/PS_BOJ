#include <iostream>
#include <vector>
#include <stack>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0 };

int Dir(char c)
{
    if (c == 'L')
        return 0;
    if (c == 'D')
        return 1;
    if (c == 'R')
        return 2;
    return 3;
}

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
    vector<vector<bool>> isSafe(n, vector<bool>(m, false));
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (isVisited[i][j])
                continue;

            int y = i;
            int x = j;

            stack<Pos> S;
            while (!isVisited[y][x])
            {
                isVisited[y][x] = true;
                S.push({ y,x });

                int ty = y;
                y += dy[Dir(map[ty][x])];
                x += dx[Dir(map[ty][x])];
            }

            if (!isSafe[y][x])
                result++;

            while (!S.empty())
            {
                isSafe[S.top().y][S.top().x] = true;
                S.pop();
            }
        }
    }

    cout << result << '\n';
}