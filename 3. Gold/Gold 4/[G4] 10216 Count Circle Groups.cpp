#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Area
{
    int x, y, r;
};

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}
void Union(int u, int v, vector<int>& p)
{
    u = Find(u, p);
    v = Find(v, p);
    if (u == v)
        return;
    p[u] = v;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<Area> areas(n);
        for (auto& area : areas)
            cin >> area.x >> area.y >> area.r;

        vector<int> p(n, -1);
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int dx = areas[i].x - areas[j].x;
                int dy = areas[i].y - areas[j].y;
                int dr = areas[i].r + areas[j].r;

                if (dx * dx + dy * dy <= dr * dr)
                    Union(i, j, p);
            }
        }

        int result = 0;
        for (int i = 0; i < n; i++)
            result += (p[i] == -1);
        cout << result << '\n';
    }
}