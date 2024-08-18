#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    int n, k;
    cin >> n >> k;

    int d = n - k;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        int r;
        cin >> r;

        sum += r;
    }

    lf(4);
    array<double, 2> result = { (double)(sum - 3 * d) / n,(double)(sum + 3 * d) / n };
    cout << result[0] << ' ' << result[1] << '\n';
}