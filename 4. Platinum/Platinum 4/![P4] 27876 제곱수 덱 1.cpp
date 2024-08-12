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
    vector<int> p(n * 2, -1);
    long long result = 1;
    int cnt = 0;

    while (true)
    {
        bool isAll = true;
        for (int i = 1; i * i < n * 2; i++)
        {
            int k = i * i;

            int l = k / 2 - (k % 2 == 0);
            int r = (k + 1) / 2 + (k % 2 == 0);
            while (l > 0 && r < k)
            {
                if (Find(l, p) == Find(r, p))
                {
                    l--, r++;
                    continue;
                }

                Union(l, r, p);
                result *= abs(l - r);
                result %= MOD;
                cnt++;
                isAll = false;
                break;
            }
            cout << result << '\n';

        }

        cout << result << '\n';
        if (isAll)
            break;
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