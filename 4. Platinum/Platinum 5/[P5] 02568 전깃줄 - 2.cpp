#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void DeleteA(int idx, int len, vector<pair<int, int>>& a, vector<int>& p, set<int>& result)
{
    if (idx == -1) return;

    if (p[idx] == len)
    {
        result.erase(a[idx].first);
        DeleteA(idx - 1, len - 1, a, p, result);
    }
    else
        DeleteA(idx - 1, len, a, p, result);
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<pair<int, int>> lines(n);
    for (auto& [u, v] : lines)
        cin >> u >> v;
    sort(lines.begin(), lines.end());

    vector<int> l(n, 0), p(n);
    set<int> result;
    int lis = 0;
    for (int i = 0; i < n; i++)
    {
        auto [u, v] = lines[i];
        result.insert(u);

        auto it = lower_bound(l.begin(), l.begin() + lis, v);
        *it = v;
        p[i] = it - l.begin() + 1;

        if (it == l.begin() + lis)
            lis++;
    }
    DeleteA(n - 1, lis, lines, p, result);

    cout << result.size() << '\n';
    for (int v : result)
        cout << v << '\n';
}