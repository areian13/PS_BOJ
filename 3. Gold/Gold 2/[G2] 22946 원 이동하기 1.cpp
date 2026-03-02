#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int MAX = 1'000'000;

struct Circle
{
    int x, y, r;

    friend bool operator < (const Circle& a, const Circle& b)
    {
        long long dx = b.x - a.x;
        long long dy = b.y - a.y;
        long long dr = b.r - a.r;
        return dx * dx + dy * dy < dr * dr;
    }
};

void DFS(int u, vector<int>& dist, vector<vector<int>>& tree)
{
    for (int v : tree[u])
    {
        if (dist[v] != MAX)
            continue;

        dist[v] = dist[u] + 1;
        DFS(v, dist, tree);
    }
}

int TreeDia(vector<vector<int>>& tree)
{
    int n = tree.size();
    vector<int> dist(n, MAX);
    dist[0] = 0;
    DFS(0, dist, tree);

    int u = max_element(dist.begin(), dist.end()) - dist.begin();
    dist.assign(n, MAX);
    dist[u] = 0;
    DFS(u, dist, tree);

    return *max_element(dist.begin(), dist.end());
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Circle> circles(n);
    for (auto& [x, y, r] : circles)
        cin >> x >> y >> r;
    circles.emplace_back(0, 0, MAX * 3);
    n++;

    sort(circles.begin(), circles.end(),
        [](const Circle& a, const Circle& b)
        { return a.r < b.r; }
    );

    vector<vector<int>> tree(n);
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (circles[i] < circles[j])
            {
                tree[i].push_back(j);
                tree[j].push_back(i);
                break;
            }
        }
    }

    int result = TreeDia(tree);
    cout << result << '\n';
}