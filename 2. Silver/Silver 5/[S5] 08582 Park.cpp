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

    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        a[i] = max(i == 0 ? 0 : a[i - 1], h[i]);

    vector<int> b(n);
    for (int i = n - 1; i >= 0; i--)
        b[i] = max(i == n - 1 ? 0 : b[i + 1], h[i]);

    for (int i = 0; i < n; i++)
        cout << a[i] << ' ' << b[i] << '\n';
}