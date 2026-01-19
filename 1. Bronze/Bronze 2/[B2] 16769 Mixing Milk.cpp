#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    vector<pair<int, int>> milk(3);
    for (auto& [c, m] : milk)
        cin >> c >> m;

    for (int i = 0; i < 100; i++)
    {
        int j = i % 3, k = (j + 1) % 3;

        int f = min(milk[j].second, (milk[k].first - milk[k].second));
        milk[j].second -= f;
        milk[k].second += f;
    }

    for (auto& [c, m] : milk)
        cout << m << '\n';
}