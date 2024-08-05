#include <iostream>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

int CatAge(int y, int m)
{
    int month = 12 * y + m;
    if (month < 12)
        return month * 15;
    if (12 <= month && month < 24)
        return 15 * 12 + 9 * m;
    return 24 * 12 + (y - 2) * 12 * 4 + m * 4;
}

int main()
{
    FastIO;

    int y, m;
    cin >> y >> m;

    int result = CatAge(y, m);
    cout << result / 12 << ' ' << result % 12 << '\n';
}
