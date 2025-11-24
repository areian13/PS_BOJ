#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Group
{
    int s, e, m;
};

int main()
{
    FastIO;

    int k, n, c;
    cin >> k >> n >> c;

    vector<Group> groups(k);
    for (auto& [s, e, m] : groups)
    {
        cin >> s >> e >> m;
        s--, e--;
    }
    sort(groups.begin(), groups.end(),
        [](auto& a, auto& b)
        { return a.s < b.s; }
    );

    multiset<int> ms;
    int result = 0;
    for (auto& [s, e, m] : groups)
    {
        while (!ms.empty() && *ms.begin() <= s)
            ms.erase(*ms.begin());

        while (m > 0 && ms.size() < c)
        {
            ms.insert(e);
            result++;
            m--;
        }
        while (m > 0 && !ms.empty() && *ms.rbegin() > e)
        {
            ms.erase(ms.find(*ms.rbegin()));
            ms.insert(e);
            m--;
        }
    }
    cout << result << '\n';
}