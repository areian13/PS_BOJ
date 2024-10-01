#include <iostream>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int x, y;
};

array<Pos, 2> GetAbleArea(int x, int y, int k, int n)
{
    if (k == 1)
        return { Pos{ 0,y },{ x - 1,y } };
    if (k == 2)
        return { Pos{ 0,y + 1 },{ x - 1,n - 1 } };
    if (k == 3)
        return { Pos{ x,y + 1 },{ x, n - 1 } };
    if (k == 4)
        return { Pos{ x + 1,y + 1 },{ n - 1,n - 1 } };
    if (k == 5)
        return { Pos{ x + 1,y },{ n - 1,y } };
    if (k == 6)
        return { Pos{ x + 1,0 },{ n - 1,y - 1 } };
    if (k == 7)
        return { Pos{ x,0 },{ x,y - 1 } };
    if (k == 8)
        return { Pos{ 0,0 },{ x - 1,y - 1 } };
    return { Pos{ -1,-1 },{ -1,-1 } };
}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> map(n, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        int x, y, k;
        cin >> x >> y >> k;
        x--, y--;

        array<Pos, 2> area = GetAbleArea(x, y, k, n);
        for (int i = area[0].x; i <= area[1].x; i++)
        {
            for (int j = area[0].y; j <= area[1].y; j++)
                map[i][j]++;
        }
    }

    Pos result = { -1,-1 };
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (map[i][j] == m)
                result = { i,j };
        }
    }
    cout << result.x + 1 << ' ' << result.y + 1 << '\n';
}