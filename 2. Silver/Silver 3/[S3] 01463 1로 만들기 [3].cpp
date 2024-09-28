#include <iostream>
#include <vector>
#include <climits>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x;
    cin >> x;

    vector<int> dist(x + 1, INT_MAX);
    dist[1] = 0;

    queue<int> Q;
    Q.push(1);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int v : { u * 3, u * 2, u + 1 })
        {
            if (v > x)
                continue;
            if (dist[v] != INT_MAX)
                continue;

            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }

    int result = dist[x];
    cout << result << '\n';
}