#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Shark
{
    int size, speed, intel;

    friend bool operator>=(const Shark& a, const Shark& b)
    {
        return a.size >= b.size && a.speed >= b.speed && a.intel >= b.intel;
    }
    friend bool operator==(const Shark& a, const Shark& b)
    {
        return a.size == b.size && a.speed == b.speed && a.intel == b.intel;
    }
    friend bool operator!=(const Shark& a, const Shark& b)
    {
        return !(a == b);
    }
};

bool CanMatch(int u, vector<bool>& isVisited,
    vector<int>& a, vector<int>& b, vector<vector<int>>& graph)
{
    isVisited[u] = true;

    for (int v : graph[u])
    {
        if (b[v] == -1 ||
            !isVisited[b[v]] && CanMatch(b[v], isVisited, a, b, graph))
        {
            a[u] = v;
            b[v] = u;
            return true;
        }
    }
    return false;
}

int MaxEat(int n, int m, vector<vector<int>>& graph)
{
    vector<int> a(n, -1), b(m, -1);
    int result = 0;
    for (int u = 0; u < n; u++)
    {
        if (a[u] != -1)
            continue;

        vector<bool> isVisited(n, false);
        result += CanMatch(u, isVisited, a, b, graph);
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<Shark> sharks(n);
    for (int i = 0; i < n; i++)
    {
        int size, speed, intel;
        cin >> size >> speed >> intel;

        sharks[i] = { size,speed,intel };
    }

    vector<vector<int>> graph(n * 2);
    for (int u = 0; u < n; u++)
    {
        for (int v = 0; v < n; v++)
        {
            if (u == v)
                continue;

            Shark& a = sharks[u];
            Shark& b = sharks[v];
            if (a >= b && ((a == b && u < v) || a != b))
            {
                graph[u * 2].push_back(v);
                graph[u * 2 + 1].push_back(v);
            }
        }
    }

    int result = n - MaxEat(n * 2, n, graph);
    cout << result << '\n';
}