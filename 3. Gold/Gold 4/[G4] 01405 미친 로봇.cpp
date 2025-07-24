#include <iostream>
#include <cstdio>
#include <vector>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 4> dy = { 0,0,1,-1 };
array<int, 4> dx = { 1,-1,0,0 };

double SimpleRoutePercentage(int y, int x, int k, int n, array<double, 4>& p, vector<vector<double>>& dist)
{
    if (k == n)
        return dist[y][x];

    double result = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (dist[ny][nx] != -1)
            continue;

        dist[ny][nx] = dist[y][x] * p[i];
        result += SimpleRoutePercentage(ny, nx, k + 1, n, p, dist);
        dist[ny][nx] = -1;
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    array<double, 4> p;
    for (int i = 0; i < 4; i++)
    {
        cin >> p[i];
        p[i] /= 100;
    }

    vector<vector<double>> dist(2 * n + 1, vector<double>(2 * n + 1, -1));
    dist[n][n] = 1;

    double result = SimpleRoutePercentage(n, n, 0, n, p, dist);
    printf("%.9lf\n", result);
}