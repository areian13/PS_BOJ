#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Point
{
    int x, y;
};

bool Exist(int x, int y, unordered_map<int, unordered_set<int>>& grid)
{
    return grid.count(x) && grid[x].count(y);
}

int main()
{
    FastIO;

    int n, a, b;
    cin >> n >> a >> b;

    vector<Point> points(n);
    unordered_map<int, unordered_set<int>> grid;
    for (auto& [x, y] : points)
    {
        cin >> x >> y;
        grid[x].insert(y);
    }

    int result = 0;
    for (auto& [x, y] : points)
        result += (Exist(x - a, y, grid) && Exist(x, y - b, grid) && Exist(x - a, y - b, grid));
    cout << result << '\n';
}