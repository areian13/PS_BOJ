#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    double a, b;
    cin >> a >> b;

    double result = a / b;

    lf(9);
    cout << result << '\n';
}