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

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int result = 0;
    for (int i = 0; i < n; i++)
    {
        vector<vector<int>> liss = { {a[i]},{-a[i]} };
        for (int j = i + 1; j < n; j++)
        {
            bool k = !(a[i] < a[j]);
            int v = (k ? -a[j] : +a[j]);
            auto& lis = liss[k];

            int p = lower_bound(lis.begin(), lis.end(), v) - lis.begin();
            if (p == lis.size()) lis.push_back(v);
            else lis[p] = v;
        }
        result = max(result, (int)(liss[0].size() + liss[1].size()) - 1);
    }
    cout << result << '\n';
}