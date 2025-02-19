#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, t;
    double pt;
    cin >> n >> pt >> t;
    long long p0 = pt * 100 + 0.5;

    vector<double> m(n);
    vector<vector<int>> indices(t);
    for (int i = 0; i < n; i++)
    {
        int s, l;
        cin >> s >> l >> m[i];
        m[i] += 1.0;

        for (int j = s; j < t; j += l)
            indices[j].push_back(i);
    }

    vector<long long> result(n, -1);
    for (int ti = 0; ti < t; ti++)
    {
        if (indices[ti].size() == 0)
            continue;

        long long sum = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (result[i] != -1)
            {
                sum += result[i];
                cnt++;
            }
        }

        double avg = (cnt == 0 ? p0 : (double)sum / cnt);
        for (int i : indices[ti])
            result[i] = avg * (cnt == 0 ? 1 : m[i]) + 0.5;
    }

    for (int i = 0; i < n; i++)
        printf("%.2lf\n", result[i] / 100.0);
}