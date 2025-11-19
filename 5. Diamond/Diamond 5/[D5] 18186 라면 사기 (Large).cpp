#include <iostream>
#include <vector>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int n, b, c;
    cin >> n >> b >> c;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    long long result = 0;
    for (int i = 0; i < n; i++)
    {
        if (b > c)
        {
            if (i < n - 2 && a[i + 1] > a[i + 2])
            {
                int k2 = min(a[i], a[i + 1] - a[i + 2]);
                a[i] -= k2;
                a[i + 1] -= k2;
                result += 1LL * k2 * (b + c);

                int k3 = min({ a[i], a[i + 1], a[i + 2] });
                a[i] -= k3;
                a[i + 1] -= k3;
                a[i + 2] -= k3;
                result += 1LL * k3 * (b + 2 * c);
            }
            else if (i < n - 2 && a[i + 1] <= a[i + 2])
            {
                int k3 = min(a[i], a[i + 1]);
                a[i] -= k3;
                a[i + 1] -= k3;
                a[i + 2] -= k3;
                result += 1LL * k3 * (b + 2 * c);
            }
            else if (i < n - 1)
            {
                int k2 = min(a[i], a[i + 1]);
                a[i] -= k2;
                a[i + 1] -= k2;
                result += 1LL * k2 * (b + c);
            }
        }

        result += 1LL * a[i] * b;
    }
    cout << result << '\n';
}