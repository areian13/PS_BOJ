#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<vector<bool>> a(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int v;
            cin >> v;

            a[i][j] = (v == 100);
        }
    }

    vector<int> l(m);
    int s = 0;
    for (int i = 0; i < m; i++)
    {
        l[i] = (a[0][i] ? 2'000 : 0);
        s += l[i];
    }

    int c = 0;
    for (int i = 0; i < n; i++)
    {
        int si = 0;
        for (int j = 0; j < m; j++)
            si += l[j] * a[i][j];
        c += (si == s);
    }
    cout << 1 << ' ' << c << '\n';
}