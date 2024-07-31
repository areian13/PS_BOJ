#include <iostream>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int main()
{
    FastIO;

    while (true)
    {
        string heisei;
        cin >> heisei;

        if (heisei == "#")
            break;

        int y, m, d;
        cin >> y >> m >> d;

        bool isHeisei = ((365 * y) + (31 * m) + d) <= ((365 * 31) + (31 * 4) + 30);
        y -= 30 * !isHeisei;

        string result = (isHeisei ? "HEISEI" : "?");
        cout << result << ' ' << y << ' ' << m << ' ' << d << '\n';
    }
}