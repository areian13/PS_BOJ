#include <iostream>
#include <bit>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 65'536

void Update(int i, int v, vector<int>& tree)
{
    int t = tree.size() / 2;

    i += t;
    tree[i] += v;

    while (i > 1)
    {
        i /= 2;
        tree[i] = tree[i * 2] + tree[i * 2 + 1];
    }
}
int Query(int s, int e, int i, int k, vector<int>& tree)
{
    if (s == e)
        return s;
    int m = (s + e) / 2;
    if (tree[i * 2] >= k)
        return Query(s, m, i * 2, k, tree);
    return Query(m + 1, e, i * 2 + 1, k - tree[i * 2], tree);
}

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    constexpr int t = bit_ceil((unsigned int)MAX);
    vector<int> tree(t * 2, 0);
    for (int i = 0; i < k - 1; i++)
        tree[t + a[i]]++;
    for (int i = t - 1; i >= 1; i--)
        tree[i] = tree[i * 2] + tree[i * 2 + 1];

    long long result = 0;
    for (int i = k - 1; i < n; i++)
    {
        Update(a[i], +1, tree);
        result += Query(0, t - 1, 1, (k + 1) / 2, tree);
        Update(a[i - k + 1], -1, tree);
    }
    cout << result << '\n';
}