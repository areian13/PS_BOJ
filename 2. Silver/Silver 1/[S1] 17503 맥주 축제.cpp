#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Beer
{
    int v, c;
};

int main()
{
    FastIO;

    int n, m, k;
    cin >> n >> m >> k;

    vector<Beer> beers(k);
    for (auto& [v, c] : beers)
        cin >> v >> c;
    sort(beers.begin(), beers.end(),
        [](const Beer& a, const Beer& b) { return a.v > b.v; }
    );

    long long s = 1, e = INT_MAX;
    int result = -1;
    while (s <= e)
    {
        long long mid = (s + e) / 2;
        int sum = 0, cnt = 0;
        for (auto& [v, c] : beers)
        {
            if (c > mid)
                continue;

            sum += v;
            cnt++;
            if (cnt == n)
                break;
        }

        if (cnt < n || sum < m)
            s = mid + 1;
        else
        {
            result = mid;
            e = mid - 1;
        }
    }
    cout << result << '\n';
}