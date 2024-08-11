#include <iostream>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout<< fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    double  t, r, v;
    cin >> t >> r >> v;

    lf(6);
    double result = max(t * v - 2 * r, 0.0) / t;
    cout << result << '\n';
}