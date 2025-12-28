#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<bool> feel(n);
    for (int i = 0; i < n; i++)
    {
        int d;
        cin >> d;
        feel[i] = (d < 0);
    }

    vector<bool> flower(n, false);
    vector<pair<int, int>> longests = { { 0,0 } };
    for (int i = 0; i < n; i++)
    {
        if (!feel[i])
            continue;

        int t = 1;
        while (i + t < n && feel[i + t])
            t++;

        if (t > longests.back().second)
            longests = { { i,t } };
        else if (t == longests.back().second)
            longests.push_back({ i,t });

        for (int j = max(i - t * 2, 0); j < i; j++)
            flower[j] = true;

        i += t;
    }
    int t3 = 0;
    for (auto& [i, t] : longests)
    {
        int cnt = 0;
        for (int j = max(i - t * 3, 0); j < i; j++)
            cnt += !flower[j];
        t3 = max(t3, cnt);
    }

    int result = t3;
    for (int i = 0; i < n; i++)
        result += flower[i];
    cout << result << '\n';
}