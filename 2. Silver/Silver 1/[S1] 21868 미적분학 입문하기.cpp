#include <iostream>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int p, q, a, b, x;
    cin >> p >> q >> a >> b >> x;

    cout << a * x + b << '\n';
    if (a == 0)
        cout << 0 << ' ' << 0 << '\n';
    else
        cout << p << ' ' << q * abs(a) << '\n';
}