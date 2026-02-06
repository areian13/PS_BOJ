#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, m;
        cin >> n >> m;

        vector<int> row(n, 0), col(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int a;
                cin >> a;
                row[i] += a;
                col[j] += a;
            }
        }

        for (int q = 0; q < m; q++)
        {
            int r1, c1, r2, c2, v;
            cin >> r1 >> c1 >> r2 >> c2 >> v;
            r1--, c1--, r2--, c2--;

            for (int i = r1; i <= r2; i++)
                row[i] += v * (c2 - c1 + 1);
            for (int j = c1; j <= c2; j++)
                col[j] += v * (r2 - r1 + 1);
        }

        for (int i = 0; i < n; i++)
            cout << row[i] << ' ';
        cout << '\n';
        for (int j = 0; j < n; j++)
            cout << col[j] << ' ';
        cout << '\n';
    }
}