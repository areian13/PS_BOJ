#include <iostream>
#include <unordered_map>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

string Find(string u, unordered_map<string, string>& p)
{
    if (p.find(u) == p.end())
        return u;
    return p[u] = Find(p[u], p);
}
void Union(string u, string v, unordered_map<string, string>& p)
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

    unordered_map<string, string> p;
    unordered_map<string, int> degree;
    bool hasInput = false;
    while (true)
    {
        string a, b;
        cin >> a >> b;

        if (cin.eof())
            break;

        hasInput = true;

        degree[a]++;
        degree[b]++;
        Union(a, b, p);
    }

    int cntH = 0, cntR = 0;
    for (auto& it : degree)
    {
        cntH += it.second % 2;
        cntR += (Find(it.first, p) == it.first);
    }

    bool result = cntR == 1 && (cntH == 0 || cntH == 2);
    if (!hasInput || result)
        cout << "Possible" << '\n';
    else
        cout << "Impossible" << '\n';
}