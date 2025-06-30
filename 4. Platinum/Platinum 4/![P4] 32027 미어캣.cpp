#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<bool> spot(n, false);
    vector<vector<int>> lr(2, vector<int>());
    for (int i = 0; i < n; i++)
    {
        int a;
        char d;
        cin >> a >> d;

        spot[i] = (d == 'R');
        lr[spot[i]].push_back(a);
    }
    sort(lr[0].begin(), lr[0].end(),
        [](auto& a, auto& b) { return a < b; }
    );
    sort(lr[1].begin(), lr[1].end(),
        [](auto& a, auto& b) { return a > b; }
    );

    vector<int> meerkats(n);
    int result = 0;
    for (int p = 0; p < 2; p++)
    {
        int s = lr[p].size();
        for (int i = 0; i < s; i++)
        {
            int j = 0, k = 0;
            for (int t = 0; t < n; t++)
                meerkats[t] = lr[spot[t]][(spot[t] ^ p) ? j++ : ((i + k++) % s)];

            vector<int> lh(n, 0), rh(n, 0);
            int lm = 0, rm = 0;
            for (int t = 0; t < n; t++)
            {
                lh[t] = lm = max(lm, meerkats[t]);
                rh[n - 1 - t] = rm = max(rm, meerkats[n - 1 - t]);
            }

            int cnt = 0;
            for (int t = 0; t < n; t++)
            {
                if (!spot[t])
                    cnt += (lh[t] <= meerkats[t]);
                else
                    cnt += (rh[t] <= meerkats[t]);
            }
            result = max(result, cnt);
        }
    }
    cout << result << '\n';
}