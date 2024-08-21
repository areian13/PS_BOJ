#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, c, w;
    cin >> n >> c >> w;

    vector<int> tree(n);
    int longTree = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
        longTree = max(longTree, tree[i]);
    }

    long long result = 0;
    for (int len = 1; len <= longTree; len++)
    {
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            if (len > tree[i])
                continue;

            long long k = tree[i] / len;
            long long t = k - (tree[i] % len == 0);

            sum += max(k * len * w - t * c, 0ll);
        }
        result = max(result, sum);
    }
    cout << result << '\n';
}