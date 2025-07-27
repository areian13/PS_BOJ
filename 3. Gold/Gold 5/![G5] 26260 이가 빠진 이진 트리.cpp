#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

void PostOder(int start, int end, vector<int>& tree)
{
    if (start >= end)
        return;
    if (start == end - 1)
    {
        cout << start << ' ' << tree[start] << '\n';
        return;
    }
    int idx = start + 1;
    while (idx < end)
    {
        if (tree[start] < tree[idx])
            break;
        idx++;
    }
    PostOder(start + 1, idx, tree);
    PostOder(idx, end, tree);
    cout << start << ' ' << tree[start] << '\n';
}

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> tree(n);
    int idx;
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
        if (tree[i] == -1)
            idx = i;
    }

    int x;
    cin >> x;
    tree[idx] = x;

    PostOder(0, n, tree);
}