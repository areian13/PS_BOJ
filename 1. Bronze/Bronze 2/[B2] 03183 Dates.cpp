#include <iostream>
#include <string>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

bool IsLeapYear(int y)
{
    return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
}

bool IsValidDate(int d, int m, int y)
{
    if (!(1 <= m && m <= 12))
        return false;

    array<int, 12> days = { 31,28,31,30,31,30,31,31,30,31,30,31 };

    bool isLeapYear = IsLeapYear(y);
    return (1 <= d && d <= days[m - 1] + (m == 2) * isLeapYear);
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

        string result = (IsValidDate(d, m, y) ? "Valid" : "Invalid");
        cout << result << '\n';
    }
}