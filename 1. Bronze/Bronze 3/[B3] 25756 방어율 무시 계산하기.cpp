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

    lf(6);
    double v = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        double result = 100 - ((100 - v) * (100 - a) / 100);
        cout << result << '\n';

        v = result;
    }
}