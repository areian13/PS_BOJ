#include <iostream>
#include <unordered_map>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int l, g, r;
    cin >> l >> g >> r;

    unordered_map<string, pair<int, int>> v;
    for (int i = 0; i < g; i++)
    {
        string n;
        int a, d;
        cin >> n >> a >> d;
        a--;

        v[n] = { a,d };
    }

    vector<bool> result(l, false);
    for (int i = 0; i < r; i++)
    {
        string n;
        cin >> n;

        for (int i = v[n].first; i < l; i += v[n].second)
            result[i] = !result[i];
    }

    int cnt = 0;
    for (int i = 0; i < l; i++)
        cnt += result[i];
    cout << cnt << '\n';
}