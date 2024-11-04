#include <iostream>
#include <array>
#include <string>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

const array<const int, 12> dayOfMonth = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const array<const string, 7> weeks = { "Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday" };

int main()
{
    FastIO;

    int d, m;
    cin >> d >> m;

    int days = d - 1;
    for (int i = 0; i < m - 1; i++)
        days += dayOfMonth[i];

    string result = weeks[((days + 3) % 7)];
    cout << result << '\n';
}