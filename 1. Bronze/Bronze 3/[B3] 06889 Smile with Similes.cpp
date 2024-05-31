#include <iostream>
#include <cstdio>
#include <vector>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<string> adj(n), noun(m);
    for (int i = 0; i < n; i++)
        cin >> adj[i];
    for (int i = 0; i < m; i++)
        cin >> noun[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%s as %s\n", adj[i].c_str(), noun[j].c_str());
    }
}