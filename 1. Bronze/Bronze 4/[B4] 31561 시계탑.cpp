#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

double CorrectMinute(double m)
{
    if (m <= 30)
        return m / 2;
    return 15 + (m - 30) * 3 / 2;
}

int main()
{
    FastIO;

    int m;
    cin >> m;

    double result = CorrectMinute(m);
    lf(1);
    cout << result << '\n';
}