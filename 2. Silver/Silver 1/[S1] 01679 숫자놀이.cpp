#include <iostream>
#include <cstdio>
#include <vector>
#include <array>
#include <queue>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];

    int k;
    cin >> k;

    array<int, 1'001> dist = { 0, };

    queue<int> Q;
    Q.push(0);

    while (!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        if (dist[u] == k)
            continue;

        for (int i = 0; i < n; i++)
        {
            int v = u + num[i];

            if (dist[v] != 0 && dist[v] <= dist[u] + 1)
                continue;

            dist[v] = dist[u] + 1;
            Q.push(v);
        }
    }

    int idx = 1;
    while (dist[idx] != 0)
        idx++;
    printf("%s win at %d\n", (idx % 2 == 0 ? "holsoon" : "jjaksoon"), idx);
}