#include <iostream>
#include <cstdio>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dx = { 1,0,-1,0 };
array<int, 4> dy = { 0,-1,0,1 };

int main()
{
    FastIO;

    while (true)
    {
        string s;
        cin >> s;

        if (cin.eof())
            break;

        int x = 30, y = 42, d = 0;
        printf("%d %d moveto\n", x * 10, y * 10);
        x += dx[d], y += dy[d];
        printf("%d %d lineto\n", x * 10, y * 10);
        for (char c : s)
        {
            if (c == 'A') d = (d + 1) % 4;
            else d = (d + 3) % 4;

            x += dx[d], y += dy[d];
            printf("%d %d lineto\n", x * 10, y * 10);
        }
        printf("stroke\nshowpage\n");
    }
}