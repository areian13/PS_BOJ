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
    int m = sqrt(n * 2);

    vector<int> x(m + 1, 0), p(n + 1, -1);
    long long result = 1;
    int cnt = 0;
    while (true)
    {
        bool isLinked = false;
        for (int s : { 3, 2 })
        {
            for (int i = s; i * i < n * 2; i += 2)
            {
                int k = i * i / 2;
                while (true)
                {
                    int u = k - x[i] - (i % 2 == 0);
                    int v = k + x[i] + 1;
                    x[i]++;

                    if (u < 1 || v > n)
                        break;
                    if (Find(u, p) == Find(v, p))
                        break;

                    Union(u, v, p);
                    result *= v - u;
                    result %= MOD;
                    cnt++;

                    isLinked = true;
                    break;
                }
            }
        }

        if (!isLinked)
            break;
    }

    if (cnt != n - 1)
        return -1;
    return result;
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    int result = MinWapasDeck(n);
    cout << result << '\n';
}