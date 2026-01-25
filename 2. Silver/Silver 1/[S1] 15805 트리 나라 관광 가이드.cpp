#include <iostream>
#include <map>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    map<int, int> parent;
    int p = -1;
    for (int i = 0; i < n; i++)
    {
        int u;
        cin >> u;

        if (parent.count(u) == 0)
            parent[u] = p;
        p = u;
    }

    cout << parent.size() << '\n';
    for (auto& [u, p] : parent)
        cout << p << ' ';
    cout << '\n';
}