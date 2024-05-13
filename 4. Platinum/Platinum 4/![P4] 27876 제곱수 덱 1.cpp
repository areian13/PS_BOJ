#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MOD 998'244'353

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}

void Union(int u, int v, vector<int>& p)
{
    p[Find(v, p)] = Find(u, p);
}

long long MinWapasDeck(int n)
{
    vector<int> p(n + 1, -1);
    long long result = 1;
    int cnt = 0;

    for (int i = 0; i < 2; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            long long r = sqrt(u) + 1;
            while (true)
            {
                long long k = r * r;
                long long v = k - u;
                r++;

                if (v > n)
                    break;
                if (v <= u)
                    continue;

                if (Find(u, p) == Find(v, p))
                    continue;

                cout << u << ' ' << v << '\n';
                Union(u, v, p);
                result *= abs(v - u);
                result %= MOD;
                cnt++;
                break;
            }
        }
    }

    if (cnt == n - 1)
        return result;
    return -1;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = MinWapasDeck(n);
    cout << result << '\n';
}