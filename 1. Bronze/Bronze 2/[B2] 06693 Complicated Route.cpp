#include <iostream>
#include <cstdio>
#include <string>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dx = { 1,0,-1,0 };
array<int, 4> dy = { 0,1,0,-1 };

int Dir(char c)
{
    if (c == 'E')
        return 0;
    if (c == 'N')
        return 1;
    if (c == 'W')
        return 2;
    return 3;
}

int main()
{
    FastIO;

    while (true)
    {
        string cmds;
        cin >> cmds;

        if (cmds == "END")
            break;

        double x = 0, y = 0;
        int i = 0;
        while (true)
        {
            string cmd = "";
            while (cmds[i] != '.' && cmds[i] != ',')
            {
                cmd += cmds[i];
                i++;
            }

            int d = 0;
            int j = 0;
            while ('0' <= cmd[j] && cmd[j] <= '9')
            {
                d *= 10;
                d += cmd[j] - '0';
                j++;
            }

            string dir = cmd.substr(j);
            bool isDiagonal = (dir.size() == 2);

            for (char c : dir)
            {
                x += dx[Dir(c)] * d * (isDiagonal ? 1 / sqrt(2) : 1);
                y += dy[Dir(c)] * d * (isDiagonal ? 1 / sqrt(2) : 1);
            }

            if (cmds[i] == '.')
                break;
            i++;
        }

        double dist = sqrt(x * x + y * y);
        printf("You can go to (%.3lf,%.3lf), ", x, y);
        printf("the distance is %.3lf steps.\n", dist);
    }
}