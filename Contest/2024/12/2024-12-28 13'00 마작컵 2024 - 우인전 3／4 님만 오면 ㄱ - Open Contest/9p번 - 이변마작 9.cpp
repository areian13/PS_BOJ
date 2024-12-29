#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <climits>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    unordered_map<string, vector<int>> idxs;
    for (int i = 0; i < n; i++)
    {
        string card;
        cin >> card;

        idxs[card].push_back(i);
    }

    int result = INT_MAX;
    for (auto& cards : idxs)
    {
        auto& idx = cards.second;
        int k = idx.size();

        if (k <= 4)
            continue;

        for (int i = 0; i < k - 4; i++)
            result = min(result, idx[i + 4] - idx[i] + 1);
    }

    if (result == INT_MAX)
        cout << -1 << '\n';
    else
        cout << result << '\n';
}