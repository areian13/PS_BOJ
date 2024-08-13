#include <iostream>
#include <array>

#define FastIO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

using namespace std;

#define MAX 5'000

int SolarEclipseDay(int ds, int ys, int dm, int ym)
{
    array<bool, MAX + 1> isSolarEclipseDay = { false, };
    for (int i = ys - ds; i <= MAX; i += ys)
        isSolarEclipseDay[i] = true;

    for (int i = ym - dm; i <= MAX; i += ym)
    {
        if (isSolarEclipseDay[i])
            return i;
    }
    return -1;
}

int main()
{
    FastIO;

    int ds, ys, dm, ym;
    cin >> ds >> ys >> dm >> ym;

    int result = SolarEclipseDay(ds, ys, dm, ym);
    cout << result << '\n';
}