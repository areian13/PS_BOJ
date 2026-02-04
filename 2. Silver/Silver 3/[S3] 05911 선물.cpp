#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, b;
    cin >> n >> b;

    vector<pair<int, int>> price(n);
    for (auto& [p, s] : price)
        cin >> p >> s;
    sort(price.begin(), price.end(),
        [](const auto& a, const auto& b)
        { return a.first + a.second < b.first + b.second;  }
    );

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        int j = 0, temp = b;
        while (j < n && temp > 0)
        {
            int a = price[j].first + price[j].second;
            int b = price[j].first / 2 + price[j].second;
            if (i != j)
            {
                if (temp >= a)
                    cnt++, temp -= a;
            }
            else
            {
                if (temp >= b)
                    cnt++, temp -= b;
            }
            j++;
        }
        result = max(result, cnt);
    }
    cout << result << '\n';
}