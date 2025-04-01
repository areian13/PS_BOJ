#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <climits>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

enum Block
{
    BLINK = -2,
    BLACK,
    RAINBOW
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

struct Pos
{
    int y, x;
};

struct Info
{
    int size = 0;
    int nofRB = 0;
    Pos pos;

    bool operator<(Info a) const
    {
        if (size != a.size)
            return size < a.size;
        if (nofRB != a.nofRB)
            return nofRB < a.nofRB;
        if (pos.y != a.pos.y)
            return pos.y < a.pos.y;
        if (pos.x != a.pos.x)
            return pos.x < a.pos.x;
    }
};

Info GetMaxBlock(int m, vector<vector<int>>& map)
{
    Info maxBlock = { 0,0,{ INT_MAX,INT_MAX } };

    int n = map.size();
    vector<vector<vector<bool>>> isVisited(n, vector<vector<bool>>(n, vector<bool>(m + 1, false)));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int stdNum = map[i][j];
            if (map[i][j] > RAINBOW && !isVisited[i][j][stdNum])
            {
                Info block = { 1,0,{ i,j } };

                isVisited[i][j][stdNum] = true;

                queue<Pos> Q;
                Q.push({ i,j });

                while (!Q.empty())
                {
                    int y = Q.front().y;
                    int x = Q.front().x;
                    Q.pop();

                    for (int k = 0; k < 4; k++)
                    {
                        int ny = y + dy[k];
                        int nx = x + dx[k];

                        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                            continue;
                        if (isVisited[ny][nx][stdNum] || (map[ny][nx] != RAINBOW && map[ny][nx] != map[i][j]))
                            continue;

                        isVisited[ny][nx][stdNum] = true;
                        block.size++;
                        block.nofRB += (map[ny][nx] == RAINBOW);
                        Q.push({ ny,nx });
                    }
                }
                maxBlock = max(maxBlock, block);
            }
        }
    }

    return maxBlock;
}

void EraseMaxBlock(Pos start, vector<vector<int>>& map)
{
    int n = map.size();

    vector<vector<bool>> isVisited(n, vector<bool>(n, false));
    isVisited[start.y][start.x] = true;

    queue<Pos> Q;
    Q.push(start);

    int stdNum = map[start.y][start.x];

    while (!Q.empty())
    {
        int y = Q.front().y;
        int x = Q.front().x;
        Q.pop();

        map[y][x] = BLINK;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;
            if (isVisited[ny][nx] || (map[ny][nx] != RAINBOW && map[ny][nx] != stdNum))
                continue;

            isVisited[ny][nx] = true;
            Q.push({ ny,nx });
        }
    }
}

void Gravity(vector<vector<int>>& map)
{
    int n = map.size();

    for (int j = 0; j < n; j++)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (map[i][j] >= RAINBOW)
            {
                int y = i;
                while (y + 1 < n && map[y + 1][j] == BLINK)
                {
                    map[y + 1][j] = map[y][j];
                    map[y][j] = BLINK;
                    y++;
                }
            }
        }
    }
}

void Spin(vector<vector<int>>& map)
{
    int n = map.size();

    vector<vector<int>> temp(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            temp[i][j] = map[j][n - i - 1];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            map[i][j] = temp[i][j];
    }
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    int result = 0;
    while (true)
    {
        Info maxBlock = GetMaxBlock(m, map);
        if (maxBlock.size < 2)
            break;
        result += pow(maxBlock.size, 2);

        EraseMaxBlock(maxBlock.pos, map);
        Gravity(map);
        Spin(map);
        Gravity(map);
    }
    cout << result << '\n';
}