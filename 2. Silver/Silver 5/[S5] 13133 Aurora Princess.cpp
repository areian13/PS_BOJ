#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<pair<int, int>> parents(n);
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        a--, b--;

        parents[i] = { a,b };
    }

    int m;
    cin >> m;

    vector<bool> isDisappeared(n, false);
    for (int i = 0; i < m; i++)
    {
        int a;
        cin >> a;
        a--;

        isDisappeared[a] = true;
    }

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        if (isDisappeared[i])
            continue;
        if (parents[i].first == -1 || isDisappeared[parents[i].first])
            continue;
        if (parents[i].second == -1 || isDisappeared[parents[i].second])
            continue;

        result++;
    }
    cout << result << '\n';
}