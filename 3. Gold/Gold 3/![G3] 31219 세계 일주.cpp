#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define INF DBL_MAX

struct Point
{
    int x, y;
};

double Dist(const Point& a, const Point& b)
{
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

double TSP(int u, int s, int t, int isVisited, vector<vector<double>>& dist,
    vector<vector<double>>& dp)
{
    int n = dp.size();
    double& result = dp[u][isVisited];

    if (result != -1)
        return result;
    if (isVisited == (((1 << n) - 1) & ~(1 << t)))
        return dist[u][t];

}

double MinDist(vector<Point>& points)
{
    int n = points.size();

    vector<vector<double>> dist(n, vector<double>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            dist[i][j] = Dist(points[i], points[j]);
    }

    vector<vector<double>> dp(n, vector<double>(1 << n, -1));
    return TSP(0, 0, 0, 1, dist, dp);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Point> points(n);
    for (auto& point : points)
        cin >> point.x >> point.y;

    double result = MinDist(points);
    printf("%.6lf\n", result);
}