#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> consumption(m);
    for (int i = 0; i < m; i++)
        cin >> consumption[i];
    sort(consumption.begin(), consumption.end(), greater<int>());

    int price = 0;
    int revenue = 0;
    for (int i = 0; i < m; i++)
    {
        if (revenue < consumption[i] * min((i + 1), n))
        {
            revenue = consumption[i] * min((i + 1), n);
            price = consumption[i];
        }
    }
    cout << price << ' ' << revenue << '\n';
}