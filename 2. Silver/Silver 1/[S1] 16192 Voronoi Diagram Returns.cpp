#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;

    static int SqrDist(const Point& a, const Point& b)
    {
        int dx = a.x - b.x;
        int dy = a.y - b.y;
        return dx * dx + dy * dy;
    }
};

void Voronoi(const Point& p, vector<Point>& points, vector<int>& voronoi)
{
    int n = points.size();
    int minDist = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int dist = Point::SqrDist(p, points[i]);
        if (dist < minDist)
            minDist = dist, voronoi = { i };
        else if (dist == minDist)
            voronoi.push_back(i);
    }
}

int main()
{
    FastIO;

    int n, QC;
    cin >> n >> QC;

    vector<Point> points(n);
    for (auto& [x, y] : points)
        cin >> x >> y;

    for (int qc = 1; qc <= QC; qc++)
    {
        int x, y;
        cin >> x >> y;

        vector<int> result;
        Voronoi({ x,y }, points, result);
        if (result.size() == 1)
            printf("REGION %d\n", result[0] + 1);
        else if (result.size() == 2)
            printf("LINE %d %d\n", result[0] + 1, result[1] + 1);
        else
            printf("POINT\n");
    }
}