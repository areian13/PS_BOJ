#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    double result = 0;
    for (int i = 0; i < n; i++)
    {
        double q, y;
        cin >> q >> y;

        result += q * y;
    }

    lf(3);
    cout << result << '\n';
}