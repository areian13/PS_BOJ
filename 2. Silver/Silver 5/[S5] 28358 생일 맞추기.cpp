#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

array<int, 12> daysPerMonth = { 31,29,31,30,31,30,31,31,30,31,30,31 };

bool IsPossibleNum(int n, array<bool, 10>& num)
{
    while (n > 0)
    {
        if (num[n % 10] == true)
            return false;
        n /= 10;
    }
    return true;
}

int CountPossibleDayPerMonth(int month, array<bool, 10>& num)
{
    if (!IsPossibleNum(month, num))
        return 0;

    int result = 0;
    for (int i = 1; i <= daysPerMonth[month - 1]; i++)
        result += IsPossibleNum(i, num);
    return result;
}

int main()
{
    FastIO;

    int tc;
    cin >> tc;

    while (tc--)
    {
        array<bool, 10> num = { false, };
        for (int i = 0; i < 10; i++)
            cin >> num[i];

        int result = 0;
        for (int i = 1; i <= 12; i++)
            result += CountPossibleDayPerMonth(i, num);
        cout << result << '\n';
    }
}