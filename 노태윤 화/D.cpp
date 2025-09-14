#include <iostream>
#include <vector>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 10'000'060

array<int, 5> dt = { +60, +10, -10, +1, -1 };

void BFS(vector<array<int, 5>>& dist)
{
    dist[0] = { 0,0,0,0,0 };
    queue<int> Q;
    Q.push(0);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for (int i = 0; i < 5; i++)
        {
            int v = u + dt[i];
            if (v < 0 || v >= MAX)
                continue;
            if (dist[v][0] != -1)
                continue;

            dist[v] = dist[u];
            dist[v][i]++;
            Q.push(v);
        }
    }
}

int main()
{
    FastIO;

    vector<array<int, 5>> dist(MAX, { -1, });
    BFS(dist);

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        for (int c : dist[n])
            cout << c << ' ';
        cout << '\n';
    }
}