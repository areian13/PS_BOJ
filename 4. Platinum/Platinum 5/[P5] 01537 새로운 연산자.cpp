#include <iostream>
#include <vector>
#include <climits>
#include <unordered_map>
#include <queue>
#include <unordered_set>
#include <array>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 4'141

struct Edge
{
    int v, w;

    friend bool operator<(const Edge& a, const Edge& b)
    {
        return a.w > b.w;
    }
};

void Calc(int n, array<array<int, 4>, MAX + 1>& dp)
{
    vector<int> ds;
    int t = min(n, MAX);
    do
    {
        int d = n % 10;
        n /= 10;

        dp[t][0] += d;
        ds.push_back(d);
    } while (n > 0);

    int k = ds.size();
    dp[t][3] = ds[k - 1];

    sort(ds.begin(), ds.end(), greater<int>());
    dp[t][2] = ds[k - 1];

    int p = min(k, 3);
    for (int i = 0; i < p; i++)
        dp[t][1] *= ds[i];
}

int XatY(int x, int y)
{
    static array<array<int, 4>, MAX + 1> dp;
    static bool isInited = false;

    if (!isInited)
    {
        fill(dp.begin(), dp.end(), array<int, 4>{ 0,1,10,-1 });
        for (int n = 0; n < MAX; n++)
            Calc(n, dp);

        isInited = true;
    }

    if (max(x, y) > MAX && dp[MAX][3] == -1)
        Calc(max(x, y), dp);

    x = min(x, MAX);
    y = min(y, MAX);

    return 5 * dp[x][1] + dp[x][3] * dp[y][0] + dp[y][2];
}

int MinAt(int x, int g)
{
    if (x == g)
        return 0;
    if (g >= MAX)
        return -1;

    vector<int> dist(MAX + 1, INT_MAX);
    dist[min(x, MAX)] = 0;
    XatY(x, x);

    priority_queue<Edge> PQ;
    PQ.push({ x,0 });

    while (!PQ.empty())
    {
        int u = PQ.top().v;
        int w = PQ.top().w;
        PQ.pop();

        if (u < MAX && dist[u] < w)
            continue;

        for (int e = 1; e <= MAX; e++)
        {
            if (dist[e] == INT_MAX)
                continue;

            for (int v : { XatY(u, e), XatY(e, u) })
            {
                int nw = w + dist[e] + 1;

                if (dist[v] <= nw || dist[g] <= nw)
                    continue;

                dist[v] = nw;
                PQ.push({ v,nw });
            }
        }
    }

    if (dist[g] == INT_MAX)
        return -1;
    return dist[g];
}

int main()
{
    FastIO;

    int x, g;
    cin >> x >> g;

    int result = MinAt(x, g);
    cout << result << '\n';
}