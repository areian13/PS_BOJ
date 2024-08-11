#include <iostream>
#include <cfloat>
#include <algorithm>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    double minValue = DBL_MAX;
    double maxValue = 0;
    double sum = 0;
    for (int i = 0; i < n; i++)
    {
        double a, b;
        cin >> a >> b;

        double value = a / b;
        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
        sum += value;
    }

    lf(6);
    cout << minValue << ' ' << maxValue << ' ' << sum << '\n';
}