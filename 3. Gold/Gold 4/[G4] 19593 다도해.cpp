#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int Find(int u, vector<int>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}
void Union(int u, int v, vector<int>& p)
{
    u = Find(u, p);
    v = Find(v, p);
    if (u == v)
        return;
    p[u] = v;
}

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        long long s, a, b;
        cin >> n >> s >> a >> b;

        vector<bool> check(n * n, false);
        vector<int> p(n, -1);
        int result = 0, cnt = 0;
        while (cnt < n - 1)
        {
            int e = s % (n * n);
            if (check[e])
            {
                result = 0;
                break;
            }
            check[e] = true;
            result++;

            int x = e / n, y = e % n;
            cnt += (Find(x, p) != Find(y, p));
            Union(x, y, p);

            s = e * a + b;
        }
        cout << result << '\n';
    }
}