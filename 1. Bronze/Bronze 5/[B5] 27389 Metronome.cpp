#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    int n;
    cin >> n;

    lf(2);
    double result = n / 4.0;
    cout << result << '\n';
}