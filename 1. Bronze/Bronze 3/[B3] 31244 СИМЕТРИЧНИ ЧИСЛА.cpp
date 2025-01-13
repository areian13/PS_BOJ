#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c;
    cin >> a >> b >> c;

    if (a == c)
        cout << a << b << a << '\n';
    else if (b == c)
        cout << a << b << b << a << '\n';
    else
        cout << a << b << c << b << a << '\n';
}