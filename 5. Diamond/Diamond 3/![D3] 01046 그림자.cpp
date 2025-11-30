#include <iostream>
#include <vector>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    double x, y;

    static double Dist(const Point& a, const Point& b)
    {
        double dx = a.x - b.x;
        double dy = a.y - b.y;
        return sqrt(dx * dx + dy * dy);
    }
};
struct Line
{
    Point p0, p1;
};

array<Line, 4> Rect(double row, double col)
{
    double u = row - 0.5, d = row + 0.5;
    double l = col - 0.5, r = col + 0.5;
    Point ul = { u,l }, ur = { u,r };
    Point dl = { d,l }, dr = { d,r };
    return { Line
        {ul,ur},{ur,dr},
        {dl,ul},{dr,dl}
    };
}

double Shadow(vector<vector<char>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();

    vector<Line> lines;
    Point light;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == '.')
                continue;
            if (grid[i][j] == '*')
            {
                light = { 1. * i,1. * j };
                continue;
            }

            for (Line& l : Rect(i, j))
                lines.push_back(l);
        }
    }

    int l = lines.size();
    for(Line& l : lines)

}

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];
    }

    double result = Shadow(grid);
    printf("%.9lf\n", result);
}