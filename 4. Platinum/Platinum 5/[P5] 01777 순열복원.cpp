#include <iostream>
#include <vector>
#include <bit>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

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

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> s(n);
    for (int i = 0; i < n; i++)
        cin >> s[i];

    int t = bit_ceil(s.size());
    vector<int> tree(t * 2, 0);
    for (int i = 0; i < n; i++)
    {

    }
}