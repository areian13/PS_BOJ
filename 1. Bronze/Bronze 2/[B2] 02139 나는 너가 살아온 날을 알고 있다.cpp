#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

int Daylize(int y, int m, int d)
{
    static array<int, 12> daysOfMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    int result = d;
    for (int i = 0; i < m - 1; i++)
        result += daysOfMonth[i] + (i == 1 && IsLeapYear(y));
    return result;
}

int main()
{
    FastIO;

    while (true)
    {
        int d, m, y;
        cin >> d >> m >> y;

        if (d == 0 && m == 0 && y == 0)
            break;

        int result = Daylize(y, m, d);
        cout << result << '\n';
    }
}