#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 2> dr = { 0,1 };
array<int, 2> dc = { 1,0 };

int Calc(int a, char op, int b)
{
    if (op == '+')
        return a + b;
    if (op == '-')
        return a - b;
    return a * b;
}

void BT(int r, int c, int w, char op, vector<vector<char>>& map,
    array<int, 2>& result)
{
    int n = map.size();

    if ((r + c) % 2 == 1)
    {
        for (int i = 0; i < 2; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= n || nc >= n)
                continue;

            BT(nr, nc, w, map[r][c], map, result);
        }
    }
    else
    {
        int nw = Calc(w, op, map[r][c] - '0');

        if (r == n - 1 && c == n - 1)
        {
            result[0] = max(result[0], nw);
            result[1] = min(result[1], nw);
            return;
        }

        for (int i = 0; i < 2; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr >= n || nc >= n)
                continue;

            BT(nr, nc, nw, -1, map, result);
        }
    }
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<vector<char>> map(n, vector<char>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> map[i][j];
    }

    array<int, 2> result = { INT_MIN,INT_MAX };
    BT(0, 0, 0, '+', map, result);
    cout << result[0] << ' ' << result[1] << '\n';
}