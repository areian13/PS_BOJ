#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int cnt = (a != d) + (b != c);
    if (cnt < 2)
    {
        cout << "JAH" << '\n';
        cout << a << ' ' << b << ' ' << b << ' ' << a << '\n';
    }
    else
        cout << "EI" << '\n';
}