#include <iostream>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static long double Dist(const Point& a, const Point& b)
    {
        long long dx = a.x - b.x;
        long long dy = a.y - b.y;
        return sqrtl(dx * dx + dy * dy);
    }
};
struct Circle
{
    Point p;
    int d;
};

int DFS(int u, vector<vector<int>>& graph, vector<bool>& visited,
    int l, int r, vector<Circle>& circles, vector<Point>& points, vector<bool>& used)
{
    int m = points.size();

    visited[u] = true;

    int result = 0;
    for (int i = 0; i < m; i++)
    {
        if (used[i])
            continue;

        if (u != 0)
        {
            Circle& circle = circles[u];
            if (Point::Dist(points[i], circle.p) <= circle.d + l)
            {
                result++;
                used[i] = true;
            }
            continue;
        }

        if (r - Point::Dist(points[i], { 0,0 }) <= l)
        {
            result++;
            used[i] = true;
        }
    }

    for (int v : graph[u])
    {
        if (visited[v])
            continue;

        result += DFS(v, graph, visited, l, r, circles, points, used);
    }
    return result;
}

int main()
{
    FastIO;

    int r, l, n, m;
    cin >> r >> l >> n >> m;

    vector<vector<int>> graph(n + 1);
    vector<Circle> circles(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int x, y, d;
        cin >> x >> y >> d;

        if (Point::Dist({ x,y }, { 0,0 }) + d >= r)
            graph[0].push_back(i);

        circles[i] = { x,y,d };
        for (int j = 1; j < i; j++)
        {
            if (Point::Dist({ x,y }, circles[j].p) <= d + circles[j].d)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }
        }
    }

    vector<Point> points(m);
    for (auto& [x, y] : points)
        cin >> x >> y;

    vector<bool> visited(n + 1, false), used(m, false);
    int result = DFS(0, graph, visited, l, r, circles, points, used);
    cout << result << '\n';
}