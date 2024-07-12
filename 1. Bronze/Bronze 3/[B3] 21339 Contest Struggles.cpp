#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    int n, k, s, d;
    cin >> n >> k >> s >> d;

    double result = ((double)n * s - k * d) / (n - k);
    if (0 <= result && result <= 100)
    {
        lf(6);
        cout << result << '\n';
    }
    else
        cout << "impossible" << '\n';
}