#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<pair<int, int>> idx(n + 1, { -1,-1 });
    for (int i = 0; i < n * 2; i++)
    {
        int a;
        cin >> a;

        if (idx[a].first == -1)
            idx[a].first = i;
        else
            idx[a].second = i;
    }

    int result = 0;
    for (int i = 1; i <= n; i++)
        result = max(result, idx[i].second - idx[i].first - 1);
    cout << result << '\n';
}