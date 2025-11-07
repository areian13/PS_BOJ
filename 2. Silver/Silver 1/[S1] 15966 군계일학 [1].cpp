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

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        pair<int, int> u = a[i];
        u.first++;
        int con = 1;
        while (i + 1 < n)
        {
            int j = lower_bound(a.begin() + i + 1, a.end(), u) - a.begin();
            pair<int, int> v = a[j];

            if (v.first == u.first && v.second > u.second)
            {
                u = v, u.first++;
                i = j;
                con++;
            }
            else
                break;
        }
        result = max(result, con);
    }
    cout << result << '\n';
}