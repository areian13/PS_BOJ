#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 1'000'000

int Find(int u, array<int, MAX>& p)
{
    if (p[u] == -1)
        return u;
    return p[u] = Find(p[u], p);
}
void Union(int u, int v, array<int, MAX>& p)
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

    int n;
    cin >> n;

    array<int, MAX> sums, p;
    sums.fill(1), p.fill(-1);
    for (int i = 0; i < n; i++)
    {
        char q;
        cin >> q;

        if (q == 'I')
        {
            int a, b;
            cin >> a >> b;
            a--, b--;

            if (Find(a, p) == Find(b, p))
                continue;

            int sum = sums[Find(a, p)] + sums[Find(b, p)];

            Union(a, b, p);
            sums[Find(a, p)] = sum;
            sums[Find(b, p)] = sum;
        }
        else
        {
            int c;
            cin >> c;
            c--;

            cout << sums[Find(c, p)] << '\n';
        }
    }
}