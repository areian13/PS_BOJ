#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Pos
{
    int r, c;
};
int Dist(const Pos& a, const Pos& b)
{
    return abs(a.r - b.r) + abs(a.c - b.c);
}

int Police(int i, int j, int n, vector<Pos>& poss,
    vector<vector<int>>& dp)
{
    int w = dp.size() - 1;
    if (i == w || j == w) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    int np = max(i, j) + 1;

    Pos ip = (i == 0 ? Pos{ 1,1 } : poss[i]);
    int inp = Dist(poss[np], ip) + Police(np, j, n, poss, dp);

    Pos jp = (j == 0 ? Pos{ n,n } : poss[j]);
    int jnp = Dist(poss[np], jp) + Police(i, np, n, poss, dp);

    return dp[i][j] = min(inp, jnp);
}
void Track(int i, int j, int n, vector<Pos>& poss,
    vector<vector<int>>& dp)
{
    int w = dp.size() - 1;
    if (i == w || j == w) return;

    int np = max(i, j) + 1;

    Pos ip = (i == 0 ? Pos{ 1,1 } : poss[i]);
    Pos jp = (j == 0 ? Pos{ n,n } : poss[j]);

    if (Dist(poss[np], ip) + dp[np][j] < Dist(poss[np], jp) + dp[i][np])
    {
        cout << 1 << '\n';
        Track(np, j, n, poss, dp);
    }
    else
    {
        cout << 2 << '\n';
        Track(i, np, n, poss, dp);
    }
}

int main()
{
    FastIO;

    int n, w;
    cin >> n >> w;

    vector<Pos> poss(w + 1);
    for (int i = 1; i <= w; i++)
        cin >> poss[i].r >> poss[i].c;

    vector<vector<int>> dp(w + 1, vector<int>(w + 1, -1));
    vector<int> seq;
    int result = Police(0, 0, n, poss, dp);
    cout << result << '\n';
    Track(0, 0, n, poss, dp);
}