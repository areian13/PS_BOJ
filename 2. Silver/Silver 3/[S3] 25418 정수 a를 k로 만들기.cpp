#include <iostream>
#include <vector>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, k;
    cin >> a >> k;

    vector<int> dist(k + 1, -1);
    dist[a] = 0;

    queue<int> Q;
    Q.push(a);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : { u + 1, u * 2 })
        {
            if (v > k)
                continue;
            if (dist[v] != -1)
                continue;

            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }
    int result = dist[k];
    cout << result << '\n';
}