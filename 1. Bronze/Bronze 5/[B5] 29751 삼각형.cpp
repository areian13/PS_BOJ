#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define lf(d) cout << fixed; cout.precision(d);
#define ulf() cout.unsetf(ios::scientific);

using namespace std;

int main()
{
    FastIO;

    double w, h;
    cin >> w >> h;


    lf(1);
    double result = w * h / 2;
    cout << result << '\n';
}