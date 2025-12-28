#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, d;
    cin >> a >> b >> c >> d;

    if (a + b <= d && c <= d)
        cout << "~.~" << '\n';
    else if (a + b > d && c > d)
        cout << "T.T" << '\n';
    else if (a + b <= d && c > d)
        cout << "Shuttle" << '\n';
    else if (a + b > d && c <= d)
        cout << "Walk" << '\n';
}