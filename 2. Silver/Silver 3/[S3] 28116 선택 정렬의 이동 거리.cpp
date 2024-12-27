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

    vector<int> a(n), idx(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
        idx[a[i]] = i;
    }

    vector<int> result(n, 0);
    for (int i = 0; i < n; i++)
    {
        int j = idx[i];

        int dist = j - i;
        result[i] += dist;
        result[a[i]] += dist;
        swap(idx[a[i]], idx[a[j]]);
        swap(a[i], a[j]);
    }

    for (int i = 0; i < n; i++)
        cout << result[i] << ' ';
    cout << '\n';
}