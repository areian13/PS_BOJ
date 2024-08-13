#include <iostream>
#include <array>
#include <cmath>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int h1, b1, h2, b2;
    cin >> h1 >> b1 >> h2 >> b2;

    int p1 = 3 * h1 + b1;
    int p2 = 3 * h2 + b2;

    if (p1 != p2)
    {
        array<int, 2> result = { (p1 > p2) ? 1 : 2,abs(p1 - p2) };
        cout << result[0] << ' ' << result[1] << '\n';
    }
    else
        cout << "NO SCORE" << '\n';
}