#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int d, y, x;
};

array<int, 4> dy = { -1,0,1,0 };
array<int, 4> dx = { 0,1,0,-1 };

int main()
{
    FastIO;

    int h, w;
    int r, c, d;
    cin >> h >> w >> r >> c >> d;

    vector<vector<vector<int>>> rule(2, vector<vector<int>>(h, vector<int>(w)));
    for (int k = 0; k < 2; k++)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                char d;
                cin >> d;

                rule[k][i][j] = d - '0';
            }
        }
    }

    vector<vector<vector<int>>> visitCnt(4, vector<vector<int>>(h, vector<int>(w, 0)));
    vector<vector<bool>> isClean(h, vector<bool>(w, false));

    Pos cur = { d,r,c };
    int result = 0;
    int dist = 0;
    while (true)
    {
        dist++;

        int d = cur.d;
        int y = cur.y;
        int x = cur.x;
        int k = isClean[y][x];

        if (visitCnt[d][y][x] > h * w)
            break;

        visitCnt[d][y][x]++;

        if (!isClean[y][x])
        {
            result += dist;
            dist = 0;
        }


        isClean[y][x] = true;

        int nd = (d + rule[k][y][x]) % 4;
        int ny = y + dy[nd];
        int nx = x + dx[nd];

        if (ny < 0 || ny >= h || nx < 0 || nx >= w)
            break;

        cur = { nd,ny,nx };
    }
    cout << result << '\n';
}
