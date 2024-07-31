#include <iostream>
#include <cfloat>
#include <algorithm>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout<<fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        int d, e;
        cin >> d >> e;

        if (d == 0 && e == 0)
            break;

        double result = DBL_MAX;
        for (int x = 0; x <= d / 2; x++)
        {
            int y = d - x;
            result = min(result, fabs(sqrt(x * x + y * y) - e));
        }

        lf(3);
        cout << result << '\n';
    }
}