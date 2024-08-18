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

    lf(5);
    while (tc--)
    {
        double p, c;
        cin >> p >> c;

        double result = p / (c / 100 + 1);
        cout << result << '\n';
    }
}