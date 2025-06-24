#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];

        int m;
        cin >> m;

        vector<int> b(m);
        for (int i = 0; i < m; i++)
            cin >> b[i];

        int result = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                result = min(result, abs(a[i] - b[j]));
        }
        cout << result << '\n';
    }
}