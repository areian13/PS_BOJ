#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct UnionFind
{
    vector<int> p;
    bool toU;

    UnionFind(int n, bool toU = false) : toU(toU) { p.resize(n, -1); }
    int Find(int u) { return p[u] < 0 ? u : p[u] = Find(p[u]); }
    void Union(int u, int v)
    {
        u = Find(u), v = Find(v);
        if (u == v)
            return;
        if (!toU && p[u] > p[v])
            swap(u, v);
        p[u] += p[v], p[v] = u;
    }
};

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;
    cin.ignore();

    vector<string> names(n);
    unordered_map<string, int> uize;
    for (int i = 0; i < n; i++)
    {
        getline(cin, names[i]);
        uize[names[i]] = i;
    }

    UnionFind uf(n, true);
    for (int i = 0; i < m; i++)
    {
        string line;
        getline(cin, line);

        int p0 = line.find(',');
        int p1 = line.rfind(',');

        int u = uize[line.substr(0, p0)];
        int v = uize[line.substr(p0 + 1, p1 - p0 - 1)];
        int win = stoi(line.substr(p1 + 1));

        if (win == 2)
            swap(u, v);

        if (uf.Find(u) == v)
        {
            uf.p[u] = uf.p[v];
            uf.p[v] = u;
            continue;
        }

        uf.Union(u, v);
    }

    vector<string> result;
    for (int i = 0; i < n; i++)
    {
        if (uf.p[i] < 0)
            result.push_back(names[i]);
    }
    sort(result.begin(), result.end());

    cout << result.size() << '\n';
    for (string& name : result)
        cout << name << '\n';
}