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

    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < n - 2 && a[i + 1] > a[i + 2])
        {
            int k2 = min(a[i], a[i + 1] - a[i + 2]);
            a[i] -= k2;
            a[i + 1] -= k2;
            result += k2 * 5;

            int k3 = min({ a[i], a[i + 1], a[i + 2] });
            a[i] -= k3;
            a[i + 1] -= k3;
            a[i + 2] -= k3;
            result += k3 * 7;
        }
        else if (i < n - 2 && a[i + 1] <= a[i + 2])
        {
            int k3 = min(a[i], a[i + 1]);
            a[i] -= k3;
            a[i + 1] -= k3;
            a[i + 2] -= k3;
            result += k3 * 7;
        }
        else if (i < n - 1)
        {
            int k2 = min(a[i], a[i + 1]);
            a[i] -= k2;
            a[i + 1] -= k2;
            result += k2 * 5;
        }
        result += a[i] * 3;
    }
    cout << result << '\n';
}