#include <iostream>
#include <vector>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = i + 1;

    for (int t = 0; t < m; t++)
    {
        int s, e, m;
        cin >> s >> e >> m;
        s--, e--, m--;

        int k = e - s + 1;
        vector<int> b = a;
        for (int i = 0; i < k; i++)
            a[s + i] = b[s + (m - s + i) % k];
    }

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ';
    cout << '\n';
}