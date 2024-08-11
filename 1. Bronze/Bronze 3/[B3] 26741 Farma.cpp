#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int x, y;
    cin >> x >> y;

    int cow = (y - 2 * x) / 2;
    int chicken = x - cow;
    cout << chicken << ' ' << cow << '\n';
}