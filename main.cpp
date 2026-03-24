#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const long long INF = LLONG_MAX;
const int SIZE = 3;
const int SQR = SIZE * SIZE;
const int MAX_VALUE = 5;

struct Point
{
    int x, y;

    friend auto operator <=> (const Point& a, const Point& b) = default;
};

int CCW(const Point& a, const Point& b, const Point& c)
{
    int ccw = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
    return (ccw > 0) - (ccw < 0);
}

bool CanGo(Point u, Point v, int visit)
{
    int sr = min(u.y, v.y), er = max(u.y, v.y);
    int sc = min(u.x, v.x), ec = max(u.x, v.x);
    for (int i = sr; i <= er; i++)
    {
        for (int j = sc; j <= ec; j++)
        {
            Point w = { j,i };
            if (u == w || v == w || (visit & (1 << (i * SIZE + j))))
                continue;
            if (CCW(u, v, w) == 0)
                return false;
        }
    }
    return true;
}

long long GP(int r, int c, int visit, vector<vector<int>>& grid,
    vector<vector<long long>>& dp)
{
    int u = r * SIZE + c;

    if (dp[u][visit] != INF) return dp[u][visit];
    if (visit == (1 << SQR) - 1) return 1;


    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int v = i * SIZE + j;
            if (visit & (1 << v))
                continue;
            if (!CanGo({ c,r }, { j,i }, visit))
                continue;
            int dr = r - i, dc = c - j;
            long long val = (grid[r][c] + grid[i][j]) * (dr * dr + dc * dc);
            dp[u][visit] = min(dp[u][visit], GP(i, j, visit | (1 << v), grid, dp) * val);
        }
    }
    return dp[u][visit];
}
long long DP(vector<vector<int>>& grid)
{
    vector<vector<long long>> dp(SQR, vector<long long>(1 << SQR, INF));
    long long result = INF;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            result = min(result, GP(i, j, 1 << (i * SIZE + j), grid, dp));
    }
    return result;
}

long long GP2(int r, int c, int visit, vector<vector<int>>& grid)
{
    int u = r * SIZE + c;

    if (visit == (1 << SQR) - 1) return 1;

    long long result = INF;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            int v = i * SIZE + j;
            if (visit & (1 << v))
                continue;
            if (!CanGo({ c,r }, { j,i }, visit))
                continue;
            int dr = r - i, dc = c - j;
            long long val = (grid[r][c] + grid[i][j]) * (dr * dr + dc * dc);
            result = min(result, GP2(i, j, visit | (1 << v), grid) * val);
        }
    }
    return result;
}
long long BT(vector<vector<int>>& grid)
{
    long long result = INF;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            result = min(result, GP2(i, j, 1 << (i * SIZE + j), grid));
    }
    return result;
}

int cnt = 0;
void MakeGrid(int idx, vector<vector<int>>& grid)
{
    if (idx == SQR)
    {
        long long a = DP(grid);
        long long b = BT(grid);
        
        if (a != b)
        {
        cout << a << ' ' << b << '\n';
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                    cout << grid[i][j] << ' ';
                cout << '\n';
            }
            cout << '\n';
        }
        return;
    }

    int r = idx / SIZE, c = idx % SIZE;
    for (int v = 1; v <= MAX_VALUE; v++)
    {
        grid[r][c] = v;
        MakeGrid(idx + 1, grid);
    }
}

int main()
{
    FastIO;

    vector<vector<int>> grid(SIZE, vector<int>(SIZE));
    MakeGrid(0, grid);
}