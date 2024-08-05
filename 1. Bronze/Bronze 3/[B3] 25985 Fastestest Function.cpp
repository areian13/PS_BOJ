#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    float x, y;
    cin >> x >> y;

    lf(6);
    float result = x * (100 - y) / ((100 - x) * y);
    cout << result << '\n';
}