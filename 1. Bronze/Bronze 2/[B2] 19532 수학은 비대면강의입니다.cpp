#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    array<int, 2> result;
    for (int x = -999; x <= 999; x++)
    {
        for (int y = -999; y <= 999; y++)
        {
            if (a * x + b * y == c && d * x + e * y == f)
                result = { x,y };
        }
    }
    cout << result[0] << ' ' << result[1] << '\n';
}