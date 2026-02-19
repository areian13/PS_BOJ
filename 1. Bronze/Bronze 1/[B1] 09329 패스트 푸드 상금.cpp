#include <iostream>
#include <vector>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const int INF = INT_MAX;

int main()
{
    FastIO;

    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; tc++)
    {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> need(n);
        vector<int> price(n);
        for (int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            need[i].resize(k);
            for (int j = 0; j < k; j++)
            {
                cin >> need[i][j];
                need[i][j]--;
            }
            cin >> price[i];
        }

        vector<int> cnt(m);
        for (int i = 0; i < m; i++)
            cin >> cnt[i];

        long long result = 0;
        for (int i = 0; i < n; i++)
        {
            int minC = INF;
            for (int p : need[i])
                minC = min(minC, cnt[p]);
            result += minC * price[i];
        }
        cout << result << '\n';
    }
}