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

array<int, 4> dy = { 0,1,0,-1 };
array<int, 4> dx = { -1,0,1,0, };

bool IsAdjacented(int cur, int n, int m)
{
    vector<vector<int>> map(n, vector<int>(n, '.'));
    Pos s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cur & (1 << i * n + j))
            {
                map[i][j] = '*';
                s = { i,j };
            }
        }
    }

    vector<vector<bool>> isVisited(n, vector<bool>(n, false));
    isVisited[s.y][s.x] = true;
    
    queue<Pos> Q;
    Q.push(s);

    int cnt = 1;
    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            if (isVisited[ny][nx] || map[ny][nx] == '.')
                continue;

            cnt++;
            isVisited[ny][nx] = true;
            Q.push({ ny,nx });
        }
    }
    return (cnt == m);
}

int main()
{
    FastIO;

    int n = 5;
    
    int m = 0;
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char map;
            cin>>map;

            if (map == '*')
            {
                m++;
                s |= (1 << i * n + j);
            }
        }
    }

    vector<int> dist(1 << n * n, -1);
    dist[s] = 0;

    queue<int> Q;
    Q.push(s);

    int result = 0;
    while (!Q.empty())
    {
        int state = Q.front();
        Q.pop();

        if (IsAdjacented(state, n, m))
        {
            result = dist[state];
            break;
        }

        for (int i = 0; i < 1 << n; i++)
        {
            if (!(state & (1 << i)))
                continue;

            int y = i / n;
            int x = i % n;

            int cur = (1 << y * n + x);

            for (int j = 0; j < 4; j++)
            {
                int ny = y + dy[j];
                int nx = x + dx[j];

                if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                    continue;

                int nxt = (1 << ny * n + nx);
                if (state & nxt || dist[state & ~cur | nxt] != -1)
                    continue;

                dist[state & ~cur | nxt] = dist[state] + 1;
                Q.push(state & ~cur | nxt);
            }
        }
    }
    cout << result << '\n';
}