#include <iostream>
#include <cstdio>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Robot
{
    int x, y, d;
};

array<int, 4> dy = { 0,+1,0,-1 };
array<int, 4> dx = { +1,0,-1,0 };

int CDTOID(char d)
{
    if (d == 'E')
        return 0;
    if (d == 'S')
        return 1;
    if (d == 'W')
        return 2;
    return 3;
}

bool Command(int t, char c, int k, vector<Robot>& robots, vector<vector<int>>& map)
{
    int a = map[0].size();
    int b = map.size();
    int n = robots.size();

    Robot& robot = robots[t];
    for (int i = 0; i < k; i++)
    {
        if (c == 'L')
            robot.d = (robot.d + 3) % 4;
        else if (c == 'R')
            robot.d = (robot.d + 1) % 4;
        else
        {
            int y = robot.y;
            int x = robot.x;
            int d = robot.d;

            int ny = y + dy[d];
            int nx = x + dx[d];

            if (ny < 0 || ny >= b || nx < 0 || nx >= a)
            {
                printf("Robot %d crashes into the wall\n", t + 1);
                return false;
            }
            else if (map[ny][nx] != -1)
            {
                printf("Robot %d crashes into robot %d\n", t + 1, map[ny][nx] + 1);
                return false;
            }

            map[ny][nx] = map[y][x];
            map[y][x] = -1;

            robot.y = ny;
            robot.x = nx;
        }
    }
    return true;
}

int main()
{
    FastIO;

    int a, b, n, m;
    cin >> a >> b >> n >> m;

    vector<vector<int>> map(b, vector<int>(a, -1));
    vector<Robot> robots(n);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        char d;
        cin >> x >> y >> d;

        x = x - 1;
        y = b - y;

        map[y][x] = i;
        robots[i] = { x,y,CDTOID(d) };
    }

    bool isSuccess = true;
    while (m--)
    {
        int x, k;
        char c;
        cin >> x >> c >> k;
        x--;

        isSuccess = Command(x, c, k, robots, map);

        if (!isSuccess)
            break;
    }
    if (isSuccess)
        printf("OK\n");
}