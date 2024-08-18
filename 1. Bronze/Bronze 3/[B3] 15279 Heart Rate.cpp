#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    lf(4);
    while (tc--)
    {
        int b;
        double p, t;
        cin >> b >> p;

        for (int d : { -1, 0, +1})
        {
            double result = 60 * (b + d) / p;
            cout << result << ' ';
        }
        cout << '\n';
    }
}