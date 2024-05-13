#ifdef ONLINE_JUDGE
#define __int128  __int128
#else
#define __int128 long long
#endif

#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

long long Dist(int u, int v, long long a, long long b, long long c,
    long long d, vector<long long>& x)
{
    if (u > v)
        swap(u, v);
    return (((__int128)x[u] * a + (__int128)x[v] * b) % c) ^ d;
}

long long MST(long long a, long long b, long long c,
    long long d, vector<long long>& x)
{
    int n = x.size();

    vector<long long> dist(n, LLONG_MAX);
    dist[0] = 0;
    vector<bool> isVisited(n, false);
    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        int u = 0;
        long long minDist = LLONG_MAX;
        
        for (int i = 0; i < n; i++)
        {
            if (!isVisited[i] && minDist > dist[i])
            {
                minDist = dist[i];
                u = i;
            }
        }

        isVisited[u] = true;
        result += minDist;
        for (int v = 0; v < n; v++)
        {
            if (isVisited[v])
                continue;
            dist[v] = min(dist[v], Dist(u, v, a, b, c, d, x));
        }
    }
    return result;
}

int main()
{
    FastIO;

    int n;
    long long a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    a %= c;
    b %= c;

    vector<long long> x(n);
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        x[i] %= c;
    }

    long long result = MST(a, b, c, d, x);;
    cout << result << '\n';
}