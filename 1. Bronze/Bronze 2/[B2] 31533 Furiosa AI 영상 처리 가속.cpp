#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    double a, m, n;
    cin >> a >> m >> n;

    if (m > n)
        swap(m, n);

    lf(6);
    double result = min(n, 2 * m / a);
    cout << result << '\n';
}