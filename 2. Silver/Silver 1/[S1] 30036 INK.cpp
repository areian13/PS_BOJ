#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int y, x;
};

array<int, 4> dy = { 1,0,-1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int Dir(char dir)
{
    if (dir == 'D')
        return 0;
    if (dir == 'R')
        return 1;
    if (dir == 'U')
        return 2;
    return 3;
}

void Move(Pos& s, char dir, vector<vector<char>>& map)
{
    int n = map.size();

    int idx = Dir(dir);

    int ny = s.y + dy[idx];
    int nx = s.x + dx[idx];

    if (ny < 0 || ny >= n || nx < 0 || nx >= n)
        return;
    if (map[ny][nx] != '.')
        return;

    map[s.y][s.x] = '.';
    map[ny][nx] = '@';
    s = { ny,nx };
}

void Jump(Pos& s, int c, int m, vector<vector<char>>& map)
{
    int n = map.size();

    for (int a = -m; a <= m; a++)
    {
        for (int b = -m; b <= m; b++)
        {
            if (abs(a) + abs(b) > m)
                continue;

            int ny = s.y + a;
            int nx = s.x + b;

            if (ny < 0 || ny >= n || nx < 0 || nx >= n)
                continue;

            if (map[ny][nx] != '.' && map[ny][nx] != '@')
                map[ny][nx] = c;
        }
    }
}

int main()
{
    FastIO;

    int i, n, k;
    string ink;
    cin>>i >> n >> k >> ink;

    vector<vector<char>> map(n, vector<char>(n));
    Pos s = { -1,-1 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>map[i][j];
            if (map[i][j] == '@')
                s = { i,j };
        }
    }
    string cmds;
    cin>> cmds;

    int m = 0;
    int cntJump = 0;

    for (char cmd : cmds)
    {
        if (cmd == 'j')
            m++;
        else if(cmd == 'J')
        {
            char c = ink[cntJump % i];
            cntJump++;

            Jump(s, c, m, map);
            m = 0;
        }
        else
            Move(s, cmd, map);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << map[i][j];
        cout << '\n';
    }
}