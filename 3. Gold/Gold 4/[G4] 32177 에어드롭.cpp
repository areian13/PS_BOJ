#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Phone
{
    int x, y, v, p;
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

    int n, k, t;
    cin >> n >> k >> t;

    vector<Phone> phones(n + 1);
    cin >> phones[n].x >> phones[n].y >> phones[n].v;
    for (int i = 0; i < n; i++)
        cin >> phones[i].x >> phones[i].y >> phones[i].v >> phones[i].p;

    vector<int> p(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (Find(i, p) == Find(j, p))
                continue;
            if (abs(phones[i].v - phones[j].v) > t)
                continue;
            int dx = phones[i].x - phones[j].x;
            int dy = phones[i].y - phones[j].y;
            if (dx * dx + dy * dy > k * k)
                continue;

            Union(i, j, p);
        }
    }

    vector<int> result;
    for (int i = 0; i < n; i++)
    {
        if (Find(n, p) == Find(i, p) && phones[i].p)
            result.push_back(i);
    }

    if (result.empty())
        cout << 0 << '\n';
    else
    {
        for (auto i : result)
            cout << i + 1 << ' ';
        cout << '\n';
    }
}