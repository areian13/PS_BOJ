#include <iostream>
#include <chrono>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;
using namespace std::chrono;

int main()
{
    FastIO;

    int n;
    cin >> n;

    year_month_day ymd{ year{2014},month{4},day{2} };
    sys_days date = sys_days(ymd) + days{ n - 1 };

    year_month_day result = year_month_day{ date };
    printf("%4d-%02d-%02d\n", result.year(), result.month(), result.day());
}