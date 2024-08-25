#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, q;
    cin >> n >> q;

    vector<int> xs(n);
    for (int i = 0; i < n; i++)
        cin >> xs[i];

    while (q--)
    {
        int t;
        cin >> t;

        if (t == 1)
        {
            int c, x;
            cin >> c >> x;

            xs[c - 1] = x;
        }
        else
        {
            int a, b;
            cin >> a >> b;

            int result = abs(xs[a - 1] - xs[b - 1]);
            cout << result << '\n';
        }
    }
}