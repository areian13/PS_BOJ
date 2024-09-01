#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

struct Info
{
    int p, i;

    friend bool operator<(const Info& a, const Info& b)
    {
        return a.p < b.p;
    }
};

int main()
{
    FastIO;

    int n;
    cin >> n;

    vector<int> idx(n);
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        idx[a[i] - 1] = i;
    }

    int m;
    cin >> m;

    while (m--)
    {
        vector<int> result = a;
        vector<int> tidx = idx;

        int l, r;
        cin >> l >> r;

        sort(tidx.begin() + l - 1, tidx.begin() + r);
        for (int i = l - 1; i < r; i++)
            result[tidx[i]] = i + 1;

        for (int i = 0; i < n; i++)
            cout << result[i] << ' ';
        cout << '\n';
    }
}