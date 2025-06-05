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
        int m, n;
        cin >> m >> n;

        vector<int> a(m);
        int s = -1;
        for (int i = 0; i < m; i++)
        {
            cin >> a[i];

            if (a[i] >= 2)
                s = i;
        }

        int result = 0;
        int d = (a[s] == 2 ? +1 : -1);
        for (int i = 0; i < n; i++)
        {
            if (s == 0)
                d = +1;
            else if (s == m - 1)
                d = -1;
            s += d;
            result += (a[s] == 0);
        }
        cout << result << '\n';
    }
}