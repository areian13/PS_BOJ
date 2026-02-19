#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

void BFS(int s, int t, int a, int b, vector<int>& dist)
{
    queue<int> q;
    q.push(s);
    dist[s] = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int d : {a, b})
        {
            int v = u + d;
            if (v > t || dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
}

int main()
{
    FastIO;

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<int> dist(n + 1, -1);
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;

        for (int j = l; j <= r; j++)
            dist[j] = INF;
    }

    BFS(0, n, a, b, dist);
    cout << dist[n] << '\n';
}