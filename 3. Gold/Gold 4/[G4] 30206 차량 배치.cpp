#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 1'000'000'007

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<int>> road(n + 1);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;

        road[a].push_back(b);
        road[b].push_back(a);
    }

    vector<int> dist(n + 1, -1);
    dist[1] = 0;

    queue<int> Q;
    Q.push(1);

    while (!Q.empty())
    {
        int cur = Q.front();
        Q.pop();

        for (int nxt : road[cur])
        {
            if (dist[nxt] != -1)
                continue;

            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }

    vector<int> cnt(n + 1);
    for (int i = 1; i <= n; i++)
        cnt[dist[i]]++;

    long long result = 1;
    for (int i = 0; i <= n; i++)
    {
        result *= (cnt[i] + 1);
        result %= MOD;
    }
    result--;

    cout << result << '\n';
}